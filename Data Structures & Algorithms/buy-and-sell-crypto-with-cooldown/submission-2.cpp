class Solution {
public:
    int helper(int ind, int buy, vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy==0){
            profit=max(helper(ind+1,0,prices,dp), -prices[ind]+helper(ind+1,1,prices,dp));

        }
        else{
            profit=max(helper(ind+1,1,prices,dp), prices[ind]+helper(ind+2,0,prices,dp));

        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                int profit=0;
                if(buy==0){
                    profit=max(dp[ind+1][0], -prices[ind]+dp[ind+1][1]);
                }
                else{
                    profit=max(dp[ind+1][1], prices[ind]+dp[ind+2][0]);
                }

                dp[ind][buy]=profit;
            }
        }

        return dp[0][0];

        
    }
};
