class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        string sign;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") st.push(stoi(tokens[i]));
            else{
                sign = tokens[i];
                if(sign=="+"){
                    int top = st.top();
                    st.pop();
                    int secondtop = st.top();
                    st.pop();
                    st.push(secondtop+top);
                }else if(sign=="-"){
                    int top = st.top();
                    st.pop();
                    int secondtop = st.top();
                    st.pop();
                    st.push(secondtop-top);
                }else if(sign=="*"){
                    int top = st.top();
                    st.pop();
                    int secondtop = st.top();
                    st.pop();
                    st.push(secondtop*top);
                }else if(sign=="/"){
                    int top = st.top();
                    st.pop();
                    int secondtop = st.top();
                    st.pop();
                    st.push(secondtop/top);
                }
            }
        }
        return st.top();
    }
};