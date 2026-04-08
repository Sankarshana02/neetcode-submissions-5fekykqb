class Solution {
public:
    void dfs(int row, int col, int delRow[], int delCol[], int n, int m, vector<vector<int>>&vis, vector<vector<int>>&heights){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n &&  ncol>=0 && ncol<m && !vis[nrow][ncol] && heights[nrow][ncol]>=heights[row][col]){
                dfs(nrow,ncol,delRow,delCol,n,m,vis,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>atl(n,vector<int>(m,0));
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        
        for(int j=0;j<m;j++){
            dfs(0,j,delRow,delCol,n,m,pac,heights);
            dfs(n-1,j,delRow,delCol,n,m,atl,heights);
        }

        for(int i=0;i<n;i++){
            dfs(i,0,delRow,delCol,n,m,pac,heights);
            dfs(i,m-1,delRow,delCol,n,m,atl,heights);
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;

        

        
    }
};
