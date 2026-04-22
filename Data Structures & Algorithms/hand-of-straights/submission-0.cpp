class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize !=0) return false;

        unordered_map<int,int>mpp;
        for(int n:hand){
            mpp[n]+=1;
        }

        priority_queue<int, vector<int>, greater<int>>minHeap;
        for(auto it:mpp){
            minHeap.push(it.first);
        }

        while(!minHeap.empty()){
            int first=minHeap.top();
            for(int i=first;i<first+groupSize;i++){
                if(mpp.find(i)==mpp.end()) return false;
                mpp[i]-=1;
                if(mpp[i]==0){
                    if(i!=minHeap.top()) return false;
                    minHeap.pop();
                }
            }
        }

        return true;
        
    }
};
