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
    pair<int,TreeNode*> postorder(TreeNode* root){
        if (!root) return {0, nullptr};
        auto left = postorder(root->left);

        auto right = postorder(root->right);

        if(left.first>right.first){
            return {1+left.first,left.second};
        }else if(left.first<right.first){
            return {1+right.first,right.second};
        }
        return {1+left.first,root};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return postorder(root).second;
    }
};