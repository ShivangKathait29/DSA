class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        unordered_map<char,int> mp;
        for(char ch : tasks){
            mp[ch]++;
        } 
        priority_queue<pair<int,char>> pq;
        for(auto &pair : mp){
            pq.push({pair.second,pair.first});
        }
        int top;
        char c;
        priority_queue<pair<int,char>> temp;
        while(!pq.empty()){
            for(int i=0;i<=n;i++){
                    if(!pq.empty()) {
                        top = pq.top().first;
                        c = pq.top().second;
                        pq.pop();
                        top-=1;
                        if(top>0){
                            temp.push({top,c});
                        }
                        ans++;
                    }else if(!temp.empty()){
                        ans++;
                    } 
            }
            while(!temp.empty()){
                pq.push({temp.top().first,temp.top().second});
                temp.pop();
            }
        }
        return ans; 
    }
};