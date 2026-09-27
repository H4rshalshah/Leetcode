class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back({v, 1}); 
            adj[v].push_back({u, 0}); 
        }

        int count = 0;
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (const auto& [neighbor, cost] : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    count += cost; 
                    q.push(neighbor);
                }
            }
        }

        return count;
    }
};