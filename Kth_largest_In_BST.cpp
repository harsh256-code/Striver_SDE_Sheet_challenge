/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    stack<TreeNode<int>* >s;
    while(root or !s.empty()){
        while(root){
            s.push(root);
            root = root->right;
        }
        //if(s.size()==0 and k>0)return -1;
        root = s.top();
        s.pop();
        if(--k==0)break;
        root = root->left;
    }
    return root==NULL?-1:root->data;
    // Write your code here.
}
