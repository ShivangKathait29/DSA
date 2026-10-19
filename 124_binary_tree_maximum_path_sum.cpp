/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int helper(TreeNode* root,int sum){
        if(!root) return 0;
        int left = helper(root->left,sum);
        int right = helper(root->right,sum);
        if(left<0) left = 0;
        if(right<0) right = 0;
        sum = root->val + left + right;
        ans = max(ans,sum);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(root && !root->left && !root->right) return root->val;
        helper(root,0);
        return ans;
    }
};