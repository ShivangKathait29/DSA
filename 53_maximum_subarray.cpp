class Solution {
public:
    int sub(vector<int>& nums,int low,int high){
        if(low==high) return nums[low];
        int mid = low + (high - low)/2;

        int left = sub(nums,low,mid);
        int right = sub(nums,mid+1,high);

        int ls = INT_MIN;
        int leftSum = 0;

        for(int i=mid;i>=low;i--){
            leftSum+=nums[i];
            ls = max(ls,leftSum);
        }

        int rs = INT_MIN;
        int rightSum = 0;

        for(int i=mid+1;i<=high;i++){
            rightSum += nums[i];
            rs = max(rs,rightSum);
        }

        int cross = ls + rs;

        return max({left,cross,right});
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int low=0,high=n-1;
        return sub(nums,low,high);
    }
};