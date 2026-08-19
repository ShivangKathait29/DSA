class Solution {
public:
    string ans;
    vector<string> result;
    void generate(int n,int first,int second){  
        if(first==n && second==n){
            result.push_back(ans);
        }
        if(first<=n){
            ans.push_back('(');
            generate(n,first+1,second);
            ans.pop_back();
        }
        if(second<first){
            ans.push_back(')');
            generate(n,first,second+1);
            ans.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n,0,0);
        return result;
    }
};