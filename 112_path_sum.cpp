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
    bool ans = false;
    void path(TreeNode* root,int targetSum){
        if(!root) return;
        if(!root->left && !root->right && root->val==targetSum){
            ans = true;
            return;
        }

        path(root->left,targetSum-root->val); 
        path(root->right,targetSum-root->val);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        path(root,targetSum);
        return ans;
    }
};