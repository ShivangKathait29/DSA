class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        vector<vector<int>> ans;
        int distance = 0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points[i].size();j++){
                distance += points[i][j]*points[i][j];
            }
                if(pq.size()<k){
                    pq.push({distance,points[i]});
                }else if(pq.top().first>distance){
                    pq.pop();
                    pq.push({distance,points[i]});
                }
                distance = 0;
            }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};