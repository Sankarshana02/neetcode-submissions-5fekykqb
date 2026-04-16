class Solution {
public:
    int helper(int ind, vector<int>&coins, int amount){
        //base case
        if(ind==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }

        int take=1e9;
        if(coins[ind]<=amount) take=1+helper(ind,coins,amount-coins[ind]);
        int notTake=helper(ind-1,coins,amount);
        return min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans= helper(n-1, coins, amount);
        if(ans==1e9) return -1;
        else return ans;

        
    }
};
