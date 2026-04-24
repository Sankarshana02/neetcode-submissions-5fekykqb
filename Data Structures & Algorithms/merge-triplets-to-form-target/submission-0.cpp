class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x=false, y=false, z=false;

        for(auto it:triplets){
            x|=(it[0]==target[0] && it[1]<=target[1] && it[2]<=target[2]);
            y|=(it[0]<=target[0] && it[1]==target[1] && it[2]<=target[2]);
            z|=(it[0]<=target[0] && it[1]<=target[1] && it[2]==target[2]);

            if(x && y && z) return true;
        }
        return false;
        
    }
};
