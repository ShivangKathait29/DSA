class Solution {
public:
    int count = 0;
    void countnumbers(vector<int>&digits,string& s,vector<bool>& used){
        if(s.size()==3){
            if(stoi(s)%2==0){
                count++;
            }
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i]) continue;
            if(s.empty() && digits[i]==0) continue;
            if(i>0 && digits[i]==digits[i-1] && !used[i-1]) continue;
            s.push_back('0'+digits[i]);
            used[i] = true;
            countnumbers(digits,s,used);
            s.pop_back();
            used[i] = false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
        vector<bool> used(digits.size(),false);
        string s;
        countnumbers(digits,s,used);
        return count;
    }
};