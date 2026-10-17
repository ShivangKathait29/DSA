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
    int helper(TreeNode* root,long long targetSum){
        if(!root) return 0;
        int count = 0;
        long long newtarget = targetSum - root->val;
        if(newtarget==0) count = 1;
        count += helper(root->left,newtarget);
        count += helper(root->right,newtarget);

        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return pathSum(root->left,targetSum) + 
        pathSum(root->right,targetSum) +
        helper(root,targetSum);
    }
};