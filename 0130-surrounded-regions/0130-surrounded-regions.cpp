class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&vis, 
    vector<vector<char>>&grid,int delrow[],int delcol[]){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,grid,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        int n =grid.size();
        int m =grid[0].size();

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]=='O'){
                vis[0][j]=1;
                dfs(0,j,vis,grid,delrow,delcol);
            }
            if(!vis[n-1][j] && grid[n-1][j]=='O'){
                vis[n-1][j]=1;
                dfs(n-1,j,vis,grid,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='O'){
                vis[i][0]=1;
                dfs(i,0,vis,grid,delrow,delcol);
            }
            if(!vis[i][m-1] && grid[i][m-1]=='O'){
                vis[i][m-1]=1;
                dfs(i,m-1,vis,grid,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 'O'){
                    grid[i][j]='X';
                } 
            }
        }
        return ;
    }
};