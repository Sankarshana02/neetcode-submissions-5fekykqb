class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>minHeap;
        int n=nums.size();
        if(n==1) return nums[0];
        minHeap.push(nums[0]);
        for(int i=1;i<n;i++){
                minHeap.push(nums[i]);
                if(minHeap.size()>k) minHeap.pop();
            

        }
        return minHeap.top();
        
    }
};
