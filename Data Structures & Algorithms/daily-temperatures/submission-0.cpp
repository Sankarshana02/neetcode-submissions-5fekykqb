class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>>st;
        vector<int>ans(n,0);
        st.push({temperatures[0],0});
        for(int i=1;i<n;i++){
            while(!st.empty() && temperatures[i]>st.top().first){
                ans[st.top().second]=i-st.top().second;
                st.pop();

            }
            st.push({temperatures[i],i});
        }
        return ans;


        
        
    }
};
