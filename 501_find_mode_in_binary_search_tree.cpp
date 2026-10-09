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
    vector<int> ans;
    int prev,count = 0,counts = 0;
    bool hasprev = false;
    void inorder(TreeNode* root){
        if(!root) return;
        
        inorder(root->left);
        if(hasprev && prev==root->val){
            count++;
        }else{
            count = 1; 
        }
        prev = root->val;
        hasprev = true;
        if(count>counts){
            ans.clear();
            counts = count;
            ans.push_back(root->val);
        }else if(count==counts){
            ans.push_back(root->val);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        ans.clear();
        count = counts = 0;
        hasprev = false;
        inorder(root);
        return ans;
    }
};