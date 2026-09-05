class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n,0);
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            suffix[i] = mini;
        }
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            if(maxi-suffix[i]<=k) return i;
        }
        return -1;
    }
};