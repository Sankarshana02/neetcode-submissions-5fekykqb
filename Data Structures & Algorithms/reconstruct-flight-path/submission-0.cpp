class Solution {
public:
    bool dfs(string src, vector<string>&ans, unordered_map<string, vector<string>>&adj, int targetLen){
        if(ans.size()==targetLen) return true;
        if(adj.find(src)==adj.end()) return false;

        vector<string>temp=adj[src];
        for(int i=0;i<temp.size();i++){
            string v=temp[i];
            adj[src].erase(adj[src].begin()+i);
            ans.push_back(v);
            if(dfs(v,ans,adj,targetLen)) return true;
            adj[src].insert(adj[src].begin()+i,v);
            ans.pop_back();
        }

        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>>adj;
        for(auto it:tickets){
            adj[it[0]];
        }

        sort(tickets.begin(), tickets.end());
        for(auto it:tickets){
            adj[it[0]].push_back(it[1]);
        }

        vector<string>ans={"JFK"};
        dfs("JFK", ans, adj, tickets.size()+1);
        return ans;
        
    }
};
