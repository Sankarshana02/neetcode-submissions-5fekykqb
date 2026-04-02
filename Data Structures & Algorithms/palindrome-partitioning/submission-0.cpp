class Solution {
public:
    bool isPalindrome(string str, int l, int r){
        while(l<r){
            if(str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void helper(int ind, string s, vector<string>&temp, vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int j=ind;j<s.length();j++){
            if(isPalindrome(s,ind,j)){
                temp.push_back(s.substr(ind,j-ind+1));
                helper(j+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        helper(0,s,temp,ans);
        return ans;
        
    }
};
