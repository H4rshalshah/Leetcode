class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        string ans;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (cnt[x] == 0)
                break;

            ans += target[i];
            cnt[x]--;
        }

        int pos = ans.size();

        if (pos < n) {
            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c]) {
                    string res = ans;
                    res += char('a' + c);
                    cnt[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (cnt[j]--) {
                            res += char('a' + j);
                        }
                    }

                    return res;
                }
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            cnt[ans[i] - 'a']++;

            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c]) {
                    string res = ans.substr(0, i);
                    res += char('a' + c);
                    cnt[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (cnt[j]--) {
                            res += char('a' + j);
                        }
                    }

                    return res;
                }
            }
        }

        return "";
    }
};