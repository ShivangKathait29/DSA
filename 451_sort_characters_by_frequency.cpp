class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &pair : mp){
            pq.push({pair.second,pair.first});
        }
        while(!pq.empty()){
            int freq = pq.top().first;
            while(freq>0){
                ans+=pq.top().second;
                freq--;
            }
            pq.pop();
        }
        return ans;
    }
};