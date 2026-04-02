class Solution {
public:
    void helper(vector<int>&candidates, int target, int ind, vector<int>&temp, vector<vector<int>>&ans, int curr){
        if(curr==target){
            ans.push_back(temp);
            return;
        }

        if(ind==candidates.size() || target<0) return;
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(curr+candidates[i]>target) break;
            temp.push_back(candidates[i]);
            helper(candidates,target,i+1,temp,ans,curr+candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates,target,0,temp,ans,0);
        return ans;
        
    }
};
