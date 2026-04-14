class Solution {
public:
    bool dfs(int node, int parent, unordered_set<int>&vis, vector<vector<int>>&adj){
        if(vis.count(node)) return false;
        vis.insert(node);
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!dfs(it,node, vis,adj)) return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1){
            return false;


        }

        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int>vis;
        if(!dfs(0,-1,vis,adj)) return false;
        return vis.size()==n;



    }
};
