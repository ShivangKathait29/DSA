class Solution {
public:
    bool check(vector<int>& candies,long long k,long long mid){
        long long count = 0;
        for(int x : candies){
            if(x>=mid) count+=ceil(x/mid);
        }
        if(count < k) return false;
        return true;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long low = 1,high = INT_MIN;
        for(long long x : candies){
            high = max(high,x);
        }
        int ans = 0;
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(check(candies,k,mid)){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans;
    }
};