#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int factor[10][4] = {
        {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0},
        {2, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1},
        {3, 0, 0, 0}, {0, 2, 0, 0}
    };

    static const int MAX2 = 47, MAX3 = 30, MAX5 = 20, MAX7 = 17;
    int dp[MAX2][MAX3][MAX5][MAX7];

    int minDigits(int a, int b, int c, int d) {
        if (a == 0 && b == 0 && c == 0 && d == 0) return 0;
        int &ans = dp[a][b][c][d];
        if (ans != -1) return ans;

        ans = 1e9;
        for (int digit = 2; digit <= 9; digit++) {
            int na = max(0, a - factor[digit][0]);
            int nb = max(0, b - factor[digit][1]);
            int nc = max(0, c - factor[digit][2]);
            int nd = max(0, d - factor[digit][3]);
            ans = min(ans, 1 + minDigits(na, nb, nc, nd));
        }
        return ans;
    }

    string buildSuffix(int len, int a, int b, int c, int d) {
        string result;
        for (int pos = 0; pos < len; pos++) {
            int remaining = len - pos - 1;
            for (int digit = 1; digit <= 9; digit++) {
                int na = max(0, a - factor[digit][0]);
                int nb = max(0, b - factor[digit][1]);
                int nc = max(0, c - factor[digit][2]);
                int nd = max(0, d - factor[digit][3]);

                if (minDigits(na, nb, nc, nd) <= remaining) {
                    result.push_back('0' + digit);
                    a = na; b = nb; c = nc; d = nd;
                    break;
                }
            }
        }
        return result;
    }

    string smallestNumber(string num, long long t) {
        int required[4] = {0, 0, 0, 0};
        int primes[4] = {2, 3, 5, 7};

        long long temp = t;
        for (int i = 0; i < 4; i++) {
            while (temp % primes[i] == 0) {
                required[i]++;
                temp /= primes[i];
            }
        }

        if (temp != 1) return "-1"; // Prime factors other than 2, 3, 5, 7 exist

        memset(dp, -1, sizeof(dp));
        int n = num.size();

        // Check if num itself contains '0'
        int zeroIdx = -1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                zeroIdx = i;
                break;
            }
        }

        vector<array<int, 4>> prefix(n + 1, {0, 0, 0, 0});
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            int digit = num[i] - '0';
            for (int j = 0; j < 4; j++)
                prefix[i + 1][j] += factor[digit][j];
        }

        // If no '0' and num already satisfies t
        if (zeroIdx == -1) {
            bool valid = true;
            for (int j = 0; j < 4; j++) {
                if (prefix[n][j] < required[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return num;
        }

        // Try to match a prefix of length i, then increase num[i]
        int limit = (zeroIdx == -1) ? n - 1 : zeroIdx;
        for (int i = limit; i >= 0; i--) {
            int currentDigit = num[i] - '0';
            for (int newDigit = currentDigit + 1; newDigit <= 9; newDigit++) {
                int need2 = max(0, required[0] - prefix[i][0] - factor[newDigit][0]);
                int need3 = max(0, required[1] - prefix[i][1] - factor[newDigit][1]);
                int need5 = max(0, required[2] - prefix[i][2] - factor[newDigit][2]);
                int need7 = max(0, required[3] - prefix[i][3] - factor[newDigit][3]);

                int suffixLength = n - i - 1;
                if (minDigits(need2, need3, need5, need7) <= suffixLength) {
                    string answer = num.substr(0, i);
                    answer.push_back('0' + newDigit);
                    answer += buildSuffix(suffixLength, need2, need3, need5, need7);
                    return answer;
                }
            }
        }

        // If no same-length answer is valid, construct string of required length
        int minLenRequired = minDigits(required[0], required[1], required[2], required[3]);
        int targetLen = max(n + 1, minLenRequired);
        
        return buildSuffix(targetLen, required[0], required[1], required[2], required[3]);
    }
};