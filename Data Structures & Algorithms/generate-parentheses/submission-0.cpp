class Solution {
public:
    void helper(int open, int close, vector<string>&res, int n, string temp){
        if(open==close && open==n){
            res.push_back(temp);
            return;
        }

        if(open<n){
            helper(open+1,close,res,n,temp+'(');
            
        }

        if(close<open){
            helper(open,close+1,res,n,temp+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp="";
        helper(0,0,res,n,temp);
        return res;
        
    }
};
