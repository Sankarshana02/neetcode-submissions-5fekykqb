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
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=word2.length();j++){
            dp[word1.length()][j]=word2.size()-j;
        }

        for(int i=0;i<=word1.length();i++){
            dp[i][word2.length()]=word1.size()-i;
        }

        for(int i=word1.length()-1;i>=0;i--){
            for(int j=word2.length()-1;j>=0;j--){
                if(word1[i]==word2[j]) dp[i][j]=dp[i+1][j+1];
                else{
                    dp[i][j]=1+min(dp[i+1][j], min(dp[i][j+1],dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
        
        
    }

};
