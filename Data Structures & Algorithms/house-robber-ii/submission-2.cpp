class Solution {
public:
    int helper(int ind, vector<int>&temp, vector<int>&dp){
        if(ind==0) return temp[ind];
        if(dp[ind]!=-1) return dp[ind];

        int take=temp[ind];
        if(ind>1) take+=helper(ind-2,temp,dp);

        int notTake=helper(ind-1,temp,dp);
        return dp[ind]=max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);

        }
        int n1=temp1.size();
        int n2=temp2.size();
        vector<int>dp1(n1,-1);
        vector<int>dp2(n2,-1);
        int ans1=helper(n1-1,temp1,dp1);
        int ans2=helper(n2-1,temp2,dp2);

        return max(ans1,ans2);
        
    }
};
