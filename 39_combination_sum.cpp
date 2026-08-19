class Solution {
public:
    vector<int> ans;
    vector<vector<int>> result;
    void combine(vector<int>& candidates, int target,int index,int sum){
        if(index>=candidates.size()) return;
        if(sum>target) return;
        if(sum==target){
            result.push_back(ans);
            return;
        }
      
            ans.push_back(candidates[index]);
            combine(candidates,target,index,sum+candidates[index]);
            ans.pop_back();
            
            combine(candidates,target,index+1,sum);
            
      
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combine(candidates,target,0,0);
        return result;
    }
};