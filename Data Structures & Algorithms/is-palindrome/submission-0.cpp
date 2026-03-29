class Solution {
public:
    bool isValid(char ch){
        return (ch>='A' && ch<='Z'|| ch>='a' && ch<='z'|| ch>='0' && ch<='9');
    }
    bool isPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            while(l<r && !isValid(s[l]))l++;
            while(r>l && !isValid(s[r])) r--;
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
            
        }
        return true;
        
    }
};
