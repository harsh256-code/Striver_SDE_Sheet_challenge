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
    TreeNode* solve(vector<int>&in,vector<int>&pos,int s,int e,int &ind,map<int,int>&m){
        if(s>e)return NULL;
        int curr = pos[ind];
        ind--;
        TreeNode *node = new TreeNode(curr);
        if(s==e)return node;
        int p = m[curr];
        node->right = solve(in,pos,p+1,e,ind,m);
        node->left = solve(in,pos,s,p-1,ind,m);
        return node;
        
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        map<int,int>m;
        int n = in.size() - 1;
        for(int i = 0;i<=n;i++){
            m[in[i]] = i;
        }
        return solve(in,pos,0,n,n,m);
    }
};
