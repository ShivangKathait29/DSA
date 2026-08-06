class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        unordered_map<char,int> mp1,mp2;
        for(char c : s1){
            mp1[c]++;
        }
        int left = 0;
        for(int right=0;right<n;right++){
            mp2[s2[right]]++;
            while(right-left+1>k){
                mp2[s2[left]]--;
                if(mp2[s2[left]]==0) mp2.erase(s2[left]);
                left++;
            }
            if(right-left+1==k && mp1==mp2) return true;
        }
        return false;
    }
};