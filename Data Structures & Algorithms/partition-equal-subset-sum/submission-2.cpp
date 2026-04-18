class Solution {
public:
    bool helper(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0){
            if(nums[ind]<=target && target-nums[ind]==0) return true;
            else return false;
                
            
        }
        
        if(target<0) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=false;
        if(nums[ind]<=target) take=helper(ind-1,target-nums[ind],nums,dp);
        bool  notTake=helper(ind-1,target,nums,dp);
        return dp[ind][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;

        for(int i=0;i<n;i++){
            totSum+=nums[i];
        }
        
        if(totSum%2!=0) return false;
        int target=totSum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return helper(n-1,target,nums,dp);

    }
};
