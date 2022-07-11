/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* build(vector<int>&p,int &i,int bound){
    if(i==p.size() or p[i]>bound)return NULL;
    TreeNode<int>* root = new TreeNode<int>(p[i++]);
    root->left = build(p,i,root->data);
    root->right = build(p,i,bound);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i =0;
    return build(preOrder,i,INT_MAX);
    // Write your code here.
}
