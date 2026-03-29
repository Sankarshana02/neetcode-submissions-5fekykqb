class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n=s.size();
        
        vector<int>temp(26,0);
        for(auto it:s){
            temp[it-'a']++;
        }

        for(auto ch: t){
            temp[ch-'a']--;
        }

        for(int i=0;i<temp.size();i++){
            if(temp[i]!=0) return false;
        }
        return true;



































        
    }
};
