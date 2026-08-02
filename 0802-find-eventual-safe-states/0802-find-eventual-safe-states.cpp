class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            for(auto it :graph[i]){
            adj[i].push_back(it);
            }
        }
        
        
        //reversing the adjacency list
        vector<vector<int>>rev(V);
        vector<int>indegree(V);
        for(int i=0;i<V;i++){
            for(auto it :adj[i]){
                //i-->it
            //it-->i
            rev[it].push_back(i);
            indegree[i]++;
            }
            
        }
        vector<int>safenodes;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0  ){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);

            for(auto it : rev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;

    }
};