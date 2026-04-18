class Solution {
public:
    int helper(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(ind==0){
            return (amount % coins[ind]==0);
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take=0;
        if(coins[ind]<=amount) take=helper(ind, amount-coins[ind], coins, dp);
        int notTake=helper(ind-1, amount, coins,dp);
        return dp[ind][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int tar=0;tar<=amount;tar++){
            dp[0][tar]=(tar%coins[0]==0);
        }

        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                int take=0;
                if(coins[ind]<=tar) take=dp[ind][tar-coins[ind]];
                int notTake=dp[ind-1][tar];
                dp[ind][tar]=take+notTake;
            }
        }
        return dp[n-1][amount];
        
    }
};
