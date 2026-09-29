class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> ans;
        int j = 0;
        for(int i=0;i<min(k, (int)nums1.size());i++){
            pq.push({nums1[i]+nums2[j],{i,j}});
        }
        
        while(!pq.empty() && ans.size()<k){
            int i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size()) pq.push({nums1[i]+nums2[j+1],{i,j+1}});
        }
        return ans;
    }
};