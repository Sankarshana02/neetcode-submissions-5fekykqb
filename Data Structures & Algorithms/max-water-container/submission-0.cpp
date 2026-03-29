class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0,l=0,r=n-1;
        while(l<r){
            maxi=max(maxi, (r-l)*min(heights[l], heights[r]));
            if(heights[l]<=heights[r])l++;
            else r--;
        }
        return maxi;
        
    }
};
