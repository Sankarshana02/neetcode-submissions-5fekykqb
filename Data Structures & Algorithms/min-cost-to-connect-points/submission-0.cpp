class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int, vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }

        int ans=0;
        unordered_set<int>st;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int cost=it.first;
            int node=it.second;

            if(st.count(node)) continue;
            st.insert(node);
            ans+=cost;
            for(auto it:adj[node]){
                int adjNode=it.second;
                int dist=it.first;
                if(!st.count(adjNode)){
                    pq.push({dist,adjNode});
                   
                }
            }
        }

        return ans;

        
    }
};
