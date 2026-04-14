class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        priority_queue<vector<int>,vector<vector<int>>, greater<>>pq;
        pq.push({grid[0][0],0,0});
       vis[0][0]=1;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int t=it[0];
            int row=it[1];
            int col=it[2];
            if(row==n-1 && col==m-1) return t;

            int delRow[]={-1,0,+1,0};
            int delCol[]={0,+1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    pq.push({max(grid[nrow][ncol], t),nrow,ncol});
                    
                }
            }
        }

        return n*m;

    }
};
