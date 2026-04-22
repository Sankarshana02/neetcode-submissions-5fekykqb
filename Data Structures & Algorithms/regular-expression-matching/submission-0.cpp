class Solution {
public:
    int helper(int i, int j, string s, string p, int n, int m, vector<vector<int>>&dp){
        if(j==m) return i==n;

        bool match=(i<n && (s[i]==p[j] || p[j]=='.'));
        if(j+1<m && p[j+1]=='*'){
            return dp[i][j]=helper(i,j+2,s,p,n,m,dp) || (match && helper(i+1,j,s,p,n,m,dp));
        }

        if(match){
            return dp[i][j]=helper(i+1,j+1,s,p,n,m,dp);
        }

        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,s,p,n,m,dp);
        
    }
};
