class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int currsum = 0;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(currsum > sum) sum = currsum;
            if(currsum<0) currsum = 0;
        }
        return sum;
    }
};