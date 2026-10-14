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
    int check(TreeNode* root){
       if(!root) return 0;

       int leftHeight = check(root->left);
       int rightHeight = check(root->right);

       if(leftHeight==-1) return -1;
       if(rightHeight==-1) return -1;

       if(abs(leftHeight-rightHeight)<=1) return 1 + max(leftHeight, rightHeight);

       return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        if(check(root)==-1) return false;
        return true;
    }
};