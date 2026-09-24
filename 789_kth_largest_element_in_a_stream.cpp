class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int kth = 0;
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i=0;i<nums.size();i++){
            if(pq.size()<k){
                pq.push(nums[i]);
            }else if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()<kth){
            pq.push(val);
        }else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        int top = pq.top();
        return top;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */