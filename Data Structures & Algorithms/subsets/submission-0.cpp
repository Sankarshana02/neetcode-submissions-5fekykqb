class Solution {
public:
    void helper(vector<int>&nums, int ind, vector<int>&temp, vector<vector<int>>&ans){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        helper(nums, ind+1, temp,ans);
        temp.pop_back();
        helper(nums,ind+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,0,temp,ans);
        return ans;
        
    }
};
