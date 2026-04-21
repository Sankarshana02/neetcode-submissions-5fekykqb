class Solution {
public:
    int helper(int ind1, int ind2, string word1, string word2,vector<vector<int>>&dp){
        if(ind1==word1.size()) return word2.size()-ind2;
        if(ind2==word2.size()) return word1.size()-ind1;
        if(word1[ind1]==word2[ind2]) return dp[ind1][ind2]=helper(ind1+1, ind2+1,word1,word2,dp);
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int res=min(helper(ind1+1,ind2,word1,word2,dp), helper(ind1,ind2+1,word1,word2,dp));
        res=min(res, helper(ind1+1,ind2+1, word1,word2,dp));
        return dp[ind1][ind2]=res+1;
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,word1,word2,dp);
        
    }
};
