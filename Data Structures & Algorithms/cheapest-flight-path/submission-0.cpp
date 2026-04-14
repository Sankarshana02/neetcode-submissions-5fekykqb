class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({it[1], it[2]});
        }

        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;

            for(auto it:adj[node]){
                int edgeWt=it.second;
                int adjNode=it.first;
                if(cost+edgeWt<dist[adjNode] && stops<=k){
                    dist[adjNode]=cost+edgeWt;
                    q.push({stops+1,{adjNode,cost+edgeWt}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        else return dist[dst];
    }
};
