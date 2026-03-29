class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int remain=target-numbers[i];
            if(mpp.find(remain)!=mpp.end()){
                return {mpp[remain]+1,i+1};
            }
            mpp[numbers[i]]=i;
        }
        return {};
    }
};
