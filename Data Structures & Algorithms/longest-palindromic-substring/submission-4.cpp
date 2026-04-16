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
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        if(n==1) return s;
        string str="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s) && (j-i+1)>maxi){
                    maxi=j-i+1;
                    str=s.substr(i,j-i+1);
                    
                }

            }
        }
        return str;
    }
};
