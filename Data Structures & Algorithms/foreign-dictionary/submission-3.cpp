class Solution {
public:
    vector<int> topoSort(int k, vector<vector<int>>& adj, vector<int>& present) {
        vector<int> inDegree(k, 0);
        vector<int> topo;

        for (int i = 0; i < k; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0 && present[i]) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0) q.push(it);
            }
        }

        return topo;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        int k = 26;
        vector<int> present(k, 0);
        vector<vector<int>> adj(k);

        for (auto w : words) {
            for (char ch : w) {
                present[ch - 'a'] = 1;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            int ptr = 0;

            while (ptr < len && s1[ptr] == s2[ptr]) {
                ptr++;
            }

            if (ptr == len && s1.size() > s2.size()) {
                return "";
            }

            if (ptr < len) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
            }
        }

        vector<int> topo = topoSort(k, adj, present);

        int countPresent = 0;
        for (int i = 0; i < k; i++) {
            if (present[i]) countPresent++;
        }

        if ((int)topo.size() != countPresent) return "";

        string ans = "";
        for (auto it : topo) {
            ans += char(it + 'a');
        }

        return ans;
    }
};