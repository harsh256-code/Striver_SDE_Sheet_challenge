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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int ans = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            int curr_m = q.front().second;
            int size = q.size();
            int left,right;
            for(int i=0;i<size;i++){
                root = q.front().first;
                int ind = q.front().second-curr_m;
                q.pop();
                if(i==0)left = ind;
                if(i==size-1)right = ind;
                
                if(root->left){
                    q.push({root->left,2ll*ind+1});
                }
                if(root->right){
                    q.push({root->right,2ll*ind+2});
                }
            }
            ans = max(ans,right-left+1);
        }
        return ans;
        
    }
};
