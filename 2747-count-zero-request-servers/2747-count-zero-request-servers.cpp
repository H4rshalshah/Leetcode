class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = queries.size();
        vector<int> ans(m);
        
        // Store queries as pair<time, original_index> and sort by time
        vector<pair<int, int>> sorted_queries(m);
        for (int i = 0; i < m; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        
        // Sort logs by time (logs[i][1])
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        vector<int> cnt(n + 1, 0);
        int active_servers = 0;
        int left = 0, right = 0;
        int num_logs = logs.size();
        
        for (const auto& [q_time, idx] : sorted_queries) {
            int start_time = q_time - x;
            
            // Expand right boundary: add logs with time <= q_time
            while (right < num_logs && logs[right][1] <= q_time) {
                int server = logs[right][0];
                if (cnt[server] == 0) {
                    active_servers++;
                }
                cnt[server]++;
                right++;
            }
            
            // Shrink left boundary: remove logs with time < start_time
            while (left < num_logs && logs[left][1] < start_time) {
                int server = logs[left][0];
                cnt[server]--;
                if (cnt[server] == 0) {
                    active_servers--;
                }
                left++;
            }
            
            ans[idx] = n - active_servers;
        }
        
        return ans;
    }
};