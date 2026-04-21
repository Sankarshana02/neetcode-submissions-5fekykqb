class Solution {
public:
    int helper(int row, int col, vector<vector<int>>&grid, int delRow[], int delCol[], int n, int m, vector<vector<int>>&dp){
        if(dp[row][col]!=-1) return dp[row][col];
        int res=1;
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]>grid[row][col]){
                res=max(res,1+helper(nrow,ncol,grid,delRow,delCol,n,m,dp));
            }
        }
        return dp[row][col]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi, helper(i,j,matrix, delRow, delCol,n,m,dp));

            }
        }

        return maxi;
        
    }
};
