class Solution {
public:
    bool smallDiv(vector<int>& nums,int threshold,int mid){
        int sum = 0;
        for(int x : nums){
            int divisor = (x+mid-1)/mid;
            sum+=divisor;
        }
        if(sum > threshold) return false;
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long ans = 0;
        long long low = 1, high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            long long mid = low + (high - low)/2;
            if(smallDiv(nums,threshold,mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};