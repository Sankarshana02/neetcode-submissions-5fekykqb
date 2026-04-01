class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,int>>maxHeap;
        for(int it=0;it<points.size();it++){
            int dist=points[it][0]*points[it][0]+points[it][1]*points[it][1];
            maxHeap.push({dist,it});
            if(maxHeap.size()>k) maxHeap.pop();
        }
        while(!maxHeap.empty()){
            auto it=maxHeap.top();
            maxHeap.pop();
            int ind=it.second;
            ans.push_back(points[ind]);
        }
        
        return ans;
    }
};
