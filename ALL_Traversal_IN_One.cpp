/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
#include<bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>>ans;
    if(!root)return ans;
    vector<int>in,pre,pos;
    stack<pair<BinaryTreeNode<int>*,int>>s;
    s.push({root,1});
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left)s.push({it.first->left,1});
        }
        
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right)s.push({it.first->right,1});
        }
        else {
            pos.push_back(it.first->data);
        }
    }
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(pos);
    return ans;
    // Write your code here.
}
