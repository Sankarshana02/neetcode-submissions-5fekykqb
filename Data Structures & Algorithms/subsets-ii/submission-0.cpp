class Solution {
public:
    void helper(int ind, vector<int>&temp, vector<vector<int>>&ans, vector<int>&nums){
        ans.push_back(temp);
        for(int j=ind;j<nums.size();j++){
            if(j>ind && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            helper(j+1, temp,ans,nums);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        helper(0,temp,ans,nums);
        return ans;
    }

};
