class Solution {
public:
    int bs(vector<int>& nums,int target,int low,int high){
        if(low>high) return -1;
            int mid = low + (high - low)/2;
            if(nums[mid]<target) return bs(nums,target,mid+1,high);
            else if(nums[mid]>target) return bs(nums,target,low,mid-1);
            else return mid;
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0,high = n-1;
        return bs(nums,target,low,high);
    }
};