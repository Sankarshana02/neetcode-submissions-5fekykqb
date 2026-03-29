class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (char ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char c=st.top();
                if((c=='('&&ch==')')||(c=='{'&& ch=='}')||(c=='[' && ch==']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
