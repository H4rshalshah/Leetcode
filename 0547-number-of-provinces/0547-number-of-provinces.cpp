class Solution {
private:
    void dfs(int node,vector<int>adjls[],vector<int> &vis){
        vis[node]=1;
        for(auto it :adjls[node]){
            if(!vis[it]){
                dfs(it,adjls,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected[0].size();
        vector<int>adjls[V];

        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);

                }
            }
        }
        vector<int>vis(V,0);
        int count=0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                count++;
                dfs(i,adjls,vis);
            }
        }
        return count;
    }
};