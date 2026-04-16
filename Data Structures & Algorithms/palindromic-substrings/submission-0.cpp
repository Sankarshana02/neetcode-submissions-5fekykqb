class Solution {
public:
    bool isPalindrome(int l, int r, string s){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)) cnt++;

            }
        }
        return cnt;
        
    }
};
