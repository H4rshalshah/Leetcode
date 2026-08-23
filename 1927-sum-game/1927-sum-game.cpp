class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int L = 0, R = 0;
        int LQ = 0, RQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                LQ++;
            else
                L += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                RQ++;
            else
                R += num[i] - '0';
        }

        return 2 * (L - R) != 9 * (RQ - LQ);
    }
};