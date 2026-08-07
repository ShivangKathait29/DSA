class Solution {
public:
    string countAndSay(int n) {
        string s;
        if(n==1) return "1";
        string f = countAndSay(n-1);
        int i = 0;
        
        while(i<f.size()){
            int count = 0;
            char ch = f[i];
            while(i<f.size() && f[i]==ch){
                count++;
                i++;
            }
            s+= to_string(count) + ch;
        }
        return s;
    }
};