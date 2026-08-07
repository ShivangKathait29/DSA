class Solution {
public:
    int compress(vector<char>& chars) {
       string s;
        int n = chars.size();

        int i = 0;

        while(i < n){
            char ch = chars[i];
            int cnt = 0;

            while(i < n && chars[i] == ch){
                cnt++;
                i++;
            }

            s += ch;

            if(cnt > 1)
                s += to_string(cnt);
        }
        chars.clear();
        for(char c : s)
            chars.push_back(c);

        return chars.size();
    }
};