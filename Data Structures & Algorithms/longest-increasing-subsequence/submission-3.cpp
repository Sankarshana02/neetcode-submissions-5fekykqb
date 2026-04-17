class Solution {
public:
    int helper(int ind, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(ind<0) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int notTake=helper(ind-1,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[ind]<nums[prev]){
            take=1+helper(ind-1,ind,nums,dp);

        }
        return dp[ind][prev+1]=max(take,notTake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        for(int ind=0;ind<n;ind++){
            for(int prev=-1;prev<n;prev++){
                int notTake=dp[ind][prev+1];
                int take=0;
                if(prev==-1 || nums[ind]<nums[prev]){
                    take=1+dp[ind][ind+1];
                }
                dp[ind+1][prev+1]=max(take,notTake);
            }
        }
        return dp[n][0];
        
    }
};
