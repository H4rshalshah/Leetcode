class Solution {
private:
    void dfs(int sr,int sc,int initcol,int delrow[],int delcol[],vector<vector<int>>&image, vector<vector<int>>&ans,int color){
        ans[sr][sc]=color;
        int n =image.size();
        int m =image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==initcol){
                ans[nrow][ncol]=color;
                dfs(nrow,ncol,initcol,delrow,delcol,image,ans,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m =image[0].size();
        vector<vector<int>>ans=image;
        int initcol=image[sr][sc];
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(sr,sc,initcol,delrow,delcol,image,ans,color);
        return ans;
    }
};