class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1,1e9);
        int maxi=INT_MIN;
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int tm=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[adjNode]){
                    dist[adjNode]=dist[node]+wt;
                    pq.push({dist[node]+wt,adjNode});
                }
            }


           

        }

        for(int i=1;i<=n;i++){
            maxi=max(maxi,dist[i]);

        }
        if(maxi==1e9) return -1;
        else return maxi;

        
    }
};
