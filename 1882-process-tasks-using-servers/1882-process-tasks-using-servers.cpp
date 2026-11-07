class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Min-heap for free servers: {weight, index}
        using FreeServer = pair<int, int>;
        priority_queue<FreeServer, vector<FreeServer>, greater<FreeServer>> free_servers;

        // Min-heap for busy servers: {free_time, weight, index}
        using BusyServer = tuple<long long, int, int>;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy_servers;

        for (int i = 0; i < n; ++i) {
            free_servers.push({servers[i], i});
        }

        vector<int> ans(m);
        long long current_time = 0;

        for (int j = 0; j < m; ++j) {
            current_time = max(current_time, (long long)j);

            // Free all servers that finished before or at current_time
            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                auto [time, weight, index] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({weight, index});
            }

            // If no servers are available, jump current_time to when the earliest server becomes free
            if (free_servers.empty()) {
                current_time = get<0>(busy_servers.top());
                while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                    auto [time, weight, index] = busy_servers.top();
                    busy_servers.pop();
                    free_servers.push({weight, index});
                }
            }

            // Pick the best available server
            auto [weight, index] = free_servers.top();
            free_servers.pop();

            ans[j] = index;
            busy_servers.push({current_time + tasks[j], weight, index});
        }

        return ans;
    }
};