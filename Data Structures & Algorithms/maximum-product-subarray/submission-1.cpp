class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int currMin=1, currMax=1;

        for(int num:nums){
            int temp=currMax*num;
            currMax=max(max(num*currMax, num*currMin), num);
            currMin=min(min(temp, num*currMin), num);
            ans=max(ans,currMax);
        }
        return ans;
        
    }
};
