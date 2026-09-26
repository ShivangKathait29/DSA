class Solution {
public:
    struct comp{
        bool operator()(pair<string,int> &a, pair<string,int> &b) {
            if (a.second == b.second)
                return a.first < b.first;  
            return a.second > b.second; 
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,comp> pq;
        for(auto &pair : mp){
            if(pq.size()<k){
                pq.push({pair.first,pair.second});
            }else if(pq.top().second<pair.second || (pair.second == pq.top().second && pair.first < pq.top().first)){
                pq.pop();
                pq.push({pair.first,pair.second});
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};