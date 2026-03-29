class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq; // stores indices

        int l = 0, r = 0;

        while (r < n) {
            // remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }

            dq.push_back(r);

            // remove out-of-window index
            if (!dq.empty() && dq.front() < l) {
                dq.pop_front();
            }

            // window size reached
            if (r - l + 1 == k) {
                ans.push_back(nums[dq.front()]);
                l++; // slide window
            }

            r++;
        }

        return ans;
    }
};