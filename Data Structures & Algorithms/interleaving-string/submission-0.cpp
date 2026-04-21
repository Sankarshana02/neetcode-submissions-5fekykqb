class Solution {
public:
    bool helper(int i, int j, int k, string s1, string s2, string s3, vector<vector<vector<int>>>&dp){
        if(k==s3.size()){
            return (i==s1.size() && j==s2.size());
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];


        if(i<s1.size() && s1[i]==s3[k]){
            if(helper(i+1,j,k+1,s1,s2,s3,dp)) return dp[i][j][k]=true;

        }

        if(j<s2.size() && s2[j]==s3[k]){
            if(helper(i,j+1,k+1,s1,s2,s3,dp)) return dp[i][j][k]=true;
        }

        return dp[i][j][k]=false;

    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1, vector<vector<int>>(s2.size()+1, vector<int>(s3.size()+1,-1)));
        return helper(0,0,0,s1,s2,s3,dp);
        
    }
};
