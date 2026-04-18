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
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

        if(nums[0]<=target)dp[0][nums[0]]=true;

        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=target;tar++){
                bool notTake=dp[ind-1][tar];
                bool take=false;
                if(nums[ind]<=tar) take=dp[ind-1][tar-nums[ind]];

                dp[ind][tar]=take || notTake;
            }
        }

        return dp[n-1][target];

    }
};
