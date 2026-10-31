#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;

        // memo[r][c][dir]: stores the landing (r, c) when entering cell (r, c) moving in direction 'dir'
        // dir = 0 (Right), dir = 1 (Down)
        vector<vector<vector<pair<int, int>>>> memo(m, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(2, {-2, -2})));

        auto get_target = [&](auto& self, int r, int c, int dir) -> pair<int, int> {
            if (r < 0 || r >= m || c < 0 || c >= n) return {-1, -1}; // Out of bounds
            if (grid[r][c] == 0) return {r, c};                    // Reached an empty cell

            if (memo[r][c][dir].first != -2) return memo[r][c][dir];

            // If grid[r][c] == 1 (Mirror):
            // Moving Right (0) reflects to Down (1) -> moves to (r + 1, c)
            // Moving Down (1) reflects to Right (0) -> moves to (r, c + 1)
            pair<int, int> res;
            if (dir == 0) {
                res = self(self, r + 1, c, 1);
            } else {
                res = self(self, r, c + 1, 0);
            }

            return memo[r][c][dir] = res;
        };

        // DP table: dp[r][c] stores unique paths to reach cell (r, c)
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] == 0) continue;

                // Try moving Right: enters (r, c + 1) moving Right (dir = 0)
                auto [nr1, nc1] = get_target(get_target, r, c + 1, 0);
                if (nr1 != -1 && nc1 != -1) {
                    dp[nr1][nc1] = (dp[nr1][nc1] + dp[r][c]) % MOD;
                }

                // Try moving Down: enters (r + 1, c) moving Down (dir = 1)
                auto [nr2, nc2] = get_target(get_target, r + 1, c, 1);
                if (nr2 != -1 && nc2 != -1) {
                    dp[nr2][nc2] = (dp[nr2][nc2] + dp[r][c]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};