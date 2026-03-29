class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int n=s.size();
        int ans=0;
        int l=0,r=0,maxf=0;
        while(r<n){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            while((r-l+1)-maxf >k){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;        
    }
};
