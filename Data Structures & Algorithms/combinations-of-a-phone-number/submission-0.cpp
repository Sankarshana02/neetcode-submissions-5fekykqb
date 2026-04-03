class Solution {
public:
    void helper(int ind, string curr, string digits,vector<string>&res,vector<string>&digitToChar){
        if(curr.size()==digits.size()){
            res.push_back(curr);
            return;

        }
        string chars=digitToChar[digits[ind]-'0'];
        for(char c:chars){
            helper(ind+1,curr+c,digits,res,digitToChar);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>res;
        vector<string>digitToChar={
            "", "","abc","def","ghi","jkl",
            "mno","pqrs","tuv","wxyz"
        };
        helper(0,"",digits,res,digitToChar);
        return res;
        

    }
};
