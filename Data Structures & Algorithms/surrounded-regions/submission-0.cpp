class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>&grid,int delRow[], int delCol[], int n, int m,vector<vector<int>>&vis){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delRow[i];
            int ncol=col+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,delRow,delCol,n,m,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board,delRow,delCol,n,m,vis);
                
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,delRow,delCol,n,m,vis);
            }
        }

        for(int j=0;j<m;j++){
            if(board[n-1][j]=='O'){
                dfs(n-1,j,board,delRow,delCol,n,m,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,delRow,delCol,n,m,vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};
