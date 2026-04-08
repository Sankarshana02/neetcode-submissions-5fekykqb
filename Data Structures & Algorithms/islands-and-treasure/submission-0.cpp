class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF=2147483647;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

        
        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int row=it.second.first;
            int col=it.second.second;
            int steps=it.first;

            grid[row][col]=steps;

            int delRow[]={-1,0,+1,0};
            int delCol[]={0,+1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==INF){
                    vis[nrow][ncol]=1;
                    q.push({steps+1,{nrow,ncol}});
                }


            }




        }
        
    }
};
