class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int row, int col, int ind, int n, int m){
        if(ind==word.size()) return true;
        if(row<0 || col<0 || row>=n || col>=m || word[ind]!=board[row][col]|| board[row][col]=='#'){
            return false;
        }

        board[row][col]='#';
        bool res=helper(board,word,row+1,col,ind+1,n,m)||
                 helper(board,word,row-1,col,ind+1,n,m)|| 
                 helper(board,word,row,col+1,ind+1,n,m)||
                 helper(board,word,row,col-1,ind+1,n,m);

        board[row][col]=word[ind];
        return res;     
                    

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(helper(board,word,i,j,0,n,m)) return true;
            }
        }
        return false;
        
    }
};
