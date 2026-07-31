class Solution {
public:
    bool check(vector<int>& position,long long m,long long mid){
        int count = 1;
        int last = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last >= mid){
                count++;
                last = position[i];
            }
        }
        if(count < m) return false;
        return true; 
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        long long low = 1,high = position[n-1] - position[0];
        int ans = 0;
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(check(position,m,mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans;
    }
};