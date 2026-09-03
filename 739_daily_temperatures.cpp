class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().second<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top().first - i;  
            }
            st.push({i,temperatures[i]});
        }
        return ans;
    }
};