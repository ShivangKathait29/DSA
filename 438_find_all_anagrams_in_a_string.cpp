class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        unordered_map<char,int> mpS,mpP;
        for(char c : p){
            mpP[c]++;
        }
        int left = 0;
        vector<int> ans;
        for(int right=0;right<s.size();right++){
            mpS[s[right]]++;
            while(right-left+1>k){
                mpS[s[left]]--;
                if(mpS[s[left]]==0) mpS.erase(s[left]);
                left++;
            }
            if(right-left+1 == k && mpS == mpP) ans.push_back(left);
        }
        return ans;
    }
};