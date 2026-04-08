class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }

        int time=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.second.first;
            int col=it.second.second;
            int tm=it.first;

            int delRow[]={-1,0,+1,0};;
            int delCol[]={0,+1,0,-1};
            time=max(tm,time);
            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({tm+1,{nrow,ncol}});

                }

            }

            

        }
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1 && vis[i][j]==0) return -1;
                }
            }
            return time;
        
    }
};
