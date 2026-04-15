class Solution {
public:
    int helper(int ind, vector<int>&cost, vector<int>&dp){
        if(ind==0 || ind==1) return cost[ind];
        if(dp[ind]!=-1) return dp[ind];
        int oneStep=cost[ind]+helper(ind-1,cost,dp);
        int twoStep=cost[ind]+helper(ind-2,cost,dp);
        return dp[ind]=min(oneStep, twoStep);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min( helper(n-1,cost,dp), helper(n-2,cost,dp));
        
    }
};
