class Solution {
public:
    bool mini(vector<int>& bloomDay, int m, int k,long long mid){
        int consecutive = 0,buckets = 0;
        for(int x : bloomDay){
            if(x <= mid){
                consecutive++;
                if(consecutive == k){
                    buckets++;
                    consecutive = 0; 
                }
            }else consecutive = 0;
        }
        if(buckets < m) return false;
        return true;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); 
        if((long long)m*k > n) return -1;
        int ans = 0;
        long long low = *min_element(bloomDay.begin(),bloomDay.end());
        long long high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(mini(bloomDay,m,k,mid)) {
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};