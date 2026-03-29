class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int remain=target-nums[i];
            if(mpp.find(remain)!=mpp.end()){
                return {mpp[remain],i};
                
            }
            else{
                mpp[nums[i]]=i;
            }
        }
        return {};
        
    }
};
