

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int numWindows = n - x + 1;
        vector<long long> cost(numWindows, 0);

        // Two multisets to maintain lower half and upper half for median tracking
        multiset<long long> left, right;
        long long sumLeft = 0, sumRight = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                long long val = *it;
                left.erase(it);
                sumLeft -= val;
                right.insert(val);
                sumRight += val;
            }
            while (left.size() < right.size()) {
                auto it = right.begin();
                long long val = *it;
                right.erase(it);
                sumRight -= val;
                left.insert(val);
                sumLeft += val;
            }
        };

        auto add = [&](long long val) {
            if (left.empty() || val <= *prev(left.end())) {
                left.insert(val);
                sumLeft += val;
            } else {
                right.insert(val);
                sumRight += val;
            }
            balance();
        };

        auto remove = [&](long long val) {
            auto itL = left.find(val);
            if (itL != left.end()) {
                left.erase(itL);
                sumLeft -= val;
            } else {
                auto itR = right.find(val);
                if (itR != right.end()) {
                    right.erase(itR);
                    sumRight -= val;
                }
            }
            balance();
        };

        // Compute cost for all windows of size x
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *prev(left.end());
                long long currentCost = (left.size() * median - sumLeft) + (sumRight - right.size() * median);
                cost[i - x + 1] = currentCost;
            }
        }

        // DP: dp[i][j] = min cost choosing j windows within first i elements of nums
        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // Option 1: Skip nums[i-1]
                dp[i][j] = dp[i - 1][j];

                // Option 2: Take window ending at index i - 1 (starts at i - x)
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
                }
            }
        }

        return dp[n][k];
    }
};