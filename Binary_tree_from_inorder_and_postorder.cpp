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
    TreeNode *solve(vector<int>&pre,int pre_start,int pre_end,vector<int>&in,int in_start,int in_end,map<int,int>&m){
        if(pre_start>pre_end or in_start>in_end)return 0;
        
        TreeNode *root = new TreeNode(pre[pre_start]);
        int i = m[pre[pre_start]];
        int ni = i-in_start;
        
        root->left = solve(pre,pre_start+1,pre_start+ni,in,in_start,i-1,m);
        root->right = solve(pre,pre_start+ni+1,pre_end,in,i+1,in_end,m);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_start = 0,pre_end = preorder.size()-1,in_start =0,in_end = inorder.size()-1;
        map<int,int>m;
        for(int i = in_start;i<=in_end;i++){
            m[inorder[i]] = i; 
        }
        
        return solve(preorder,pre_start,pre_end,inorder,in_start,in_end,m);
    }
};
