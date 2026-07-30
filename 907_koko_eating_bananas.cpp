class Solution {
public:
    bool minEat(vector<int>& piles,int h,int mid){
        long long total = 0;
        for(int x : piles){
            int operation = 0;
            if(x<=mid) operation = 1;
            if(x%mid!=0)operation = x/mid + 1;
            else operation = x/mid;
            total+=operation;
        }
        if(total > h) return false;

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(minEat(piles,h,mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};