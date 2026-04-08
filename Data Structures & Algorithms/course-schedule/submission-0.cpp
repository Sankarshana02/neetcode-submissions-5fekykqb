class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        queue<int>q;

        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }

        vector<int>inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }

        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0)q.push(i);
        }

        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
        return cnt==numCourses;

        
    }
};
