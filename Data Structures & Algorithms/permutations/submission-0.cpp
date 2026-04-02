class Solution {
public:
    void helper(vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans, vector<int>&flag){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!flag[i]){
                temp.push_back(nums[i]);
                flag[i]=true;
                helper(nums,temp,ans,flag);
                temp.pop_back();
                flag[i]=false;

            }
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>flag(nums.size(), false);
        helper(nums,temp,ans, flag);
        return ans;
        
        
    }
};
