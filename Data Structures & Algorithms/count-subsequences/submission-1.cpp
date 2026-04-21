class Solution {
public:
    int helper(int sInd,int tInd, string s, string t, vector<vector<int>>&dp){
        if(tInd==t.size()) return 1;
        if(sInd==s.size()) return 0;
        if(dp[sInd][tInd]!=-1) return dp[sInd][tInd];

        int notTake=helper(sInd+1, tInd,s,t,dp);
        int take=0;
        if(s[sInd]==t[tInd]){
            take=helper(sInd+1, tInd+1,s,t,dp);
            
        }

        return dp[sInd][tInd]=take+notTake;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,s,t,dp);
        
    }
};
