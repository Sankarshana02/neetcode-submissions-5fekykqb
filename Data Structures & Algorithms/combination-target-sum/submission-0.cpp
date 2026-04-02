class Solution {
public:
    void helper(vector<int>&nums, int target, vector<int>&temp, vector<vector<int>>&ans, int ind){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind==nums.size() || target<0) return ;
        if(nums[ind]<=target){
            temp.push_back(nums[ind]);
            helper(nums, target-nums[ind],temp,ans,ind);
            temp.pop_back();
            
        }
        
        helper(nums,target,temp,ans,ind+1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,target,temp,ans,0);
        return ans;
        
    }
};
