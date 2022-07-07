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
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool l = 1;
        while(!q.empty()){
            int k = q.size();
            vector<int>level(k);
            for(int i = 0;i<k;i++){
                root = q.front();
                q.pop();
                int ind = l?i:(k-i-1);
                level[ind] = (root->val);
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            ans.push_back(level);
            l = !l;
        }
        return ans;
    }
};
