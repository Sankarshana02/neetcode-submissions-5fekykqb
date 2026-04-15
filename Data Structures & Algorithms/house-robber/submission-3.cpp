class Solution {
public:
    int helper(int ind, vector<int>&nums, vector<int>&dp){
        if(ind==0) return nums[ind];
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind];
        if(ind>0) take+=helper(ind-2,nums,dp);
        int notTake=0;
        if(ind>0) notTake+=helper(ind-1,nums,dp);
        return dp[ind]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        int prev= nums[0];
        int prev2=0;

        for(int ind=0;ind<n;ind++){
            if(ind==0) continue;
            int take=nums[ind];
            if(ind>1) take+=prev2;
            int notTake=0;
            notTake+=prev;
            int curr=max(take, notTake);
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};
