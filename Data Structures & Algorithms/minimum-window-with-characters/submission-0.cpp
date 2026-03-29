class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        unordered_map<char,int>countT, window;
        for(char c:t)countT[c]++;
        int have=0, need=countT.size();
        pair<int,int>res={-1,-1};
        int resLen=INT_MAX, n=s.size();
        int l=0, r=0;
        while(r<n){
            char ch=s[r];
            window[ch]++;
            if(countT.count(ch) && window[ch]==countT[ch])have++;
            while(have==need){
                if((r-l+1)<resLen){
                    resLen=(r-l+1);
                    res={l,r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]]<countT[s[l]]) have--;
                l++;
            }
            r++;
            
        }

        return resLen==INT_MAX  ? "":s.substr(res.first,resLen);
        
    }
};
