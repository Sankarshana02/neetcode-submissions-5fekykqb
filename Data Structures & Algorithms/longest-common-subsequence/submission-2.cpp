class Solution {
public:
    int helper(int ind1, int ind2, string text1, string text2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0) return 0;
        if(text1[ind1]==text2[ind2]) return dp[ind1][ind2]=1+helper(ind1-1, ind2-1,text1,text2,dp);
        int left=helper(ind1-1, ind2, text1,text2,dp);
        int right=helper(ind1, ind2-1, text1,text2,dp);

        return dp[ind1][ind2]=max(left,right);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int ind1=1;ind1<=text1.size();ind1++){
            for(int ind2=1;ind2<=text2.size();ind2++){
                if(text1[ind1-1]==text2[ind2-1]) dp[ind1][ind2]=1+dp[ind1-1][ind2-1];

                else{
                    int left=dp[ind1-1][ind2];
                    int right=dp[ind1][ind2-1];
                    dp[ind1][ind2]=max(left,right);
                }
            }
        }
        return dp[n][m];
        
    }
};
