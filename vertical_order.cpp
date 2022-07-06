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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            root = q.front().first;
            int level = q.front().second.second;
            int vertical = q.front().second.first;
            nodes[vertical][level].insert(root->val);
            q.pop();
            if(root->left){
                q.push({root->left,{vertical-1,level+1}});
            }
            if(root->right){
                q.push({root->right,{vertical+1,level+1}});
            }
        }
        for(auto p:nodes){
            vector<int>col;
            for(auto it:p.second){
                col.insert(col.end(),it.second.begin(),it.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
