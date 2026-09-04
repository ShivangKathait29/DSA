class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini = INT_MAX, maxi = INT_MIN;
        vector<int> suffix(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            mini = min(mini, nums[i]);
            suffix[i] = mini;
        }
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            int check = maxi - suffix[i];
            if(check<=k)  return i;
        }
        return -1;
    }
};