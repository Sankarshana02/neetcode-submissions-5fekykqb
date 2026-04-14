class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        vector<int>inDegree(n+1,0);
        queue<int>q;

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            inDegree[u]++;
            inDegree[v]++;
        }

        for(int i=1;i<=n;i++){
            if(inDegree[i]==1) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            inDegree[node]--;
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==1)q.push(it);
            }
        }

        for(int i=edges.size()-1;i>=0;i--){
            int u=edges[i][0];
            int v=edges[i][1];
            if(inDegree[u]==2 && inDegree[v]) return {u,v};
            
        }

        return {};

        
    }
};
