class Solution {
public:
    void dfs(int row,int col, vector<vector<char>>&grid, vector<vector<int>>&vis, int delRow[], int delCol[], int n, int m){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]!=1){
                dfs(nrow,ncol,grid,vis,delRow,delCol,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,grid,vis,delRow,delCol,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};
