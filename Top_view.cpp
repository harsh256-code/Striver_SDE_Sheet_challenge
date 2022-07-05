/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int>ans;
    if(!root)return ans;
    queue<pair<TreeNode<int>*,int>>q;
    map<int,int>m;
    q.push({root,0});
    while(!q.empty()){
        root = q.front().first;
        int line = q.front().second;
        q.pop();
        if(m.find(line)==m.end())m[line]=root->val;
        
        if(root->left)q.push({root->left,line-1});
        if(root->right)q.push({root->right,line+1});
        
    }
    for(auto it:m)ans.push_back(it.second);
    return ans;
    // Write your code here.
}
