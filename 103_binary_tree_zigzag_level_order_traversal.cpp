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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            vector<int> ans;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* top = q.front();
                q.pop();
                ans.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);  
            }
            if(level % 2 == 1) {
                reverse(ans.begin(), ans.end());
            }

            result.push_back(ans);
            level++;
        }
        return result;
    }
};