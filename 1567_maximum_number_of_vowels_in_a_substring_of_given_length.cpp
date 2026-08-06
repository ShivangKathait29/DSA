class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int> mp = {
            {'a',0},{'e',0},{'i',0},{'o',0},{'u',0}
        };
        int ans = INT_MIN;
        int left = 0;
        int count = 0;
        for(int right=0;right<s.size();right++){
            if(mp.find(s[right])!=mp.end()){
                count++;
            }
            if(right-left+1>k){  
                if(mp.find(s[left])!=mp.end()){
                    count--;
                }
                left++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};