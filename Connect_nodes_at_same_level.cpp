/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    if(!root)return;
    queue<BinaryTreeNode< int > *>q;
    q.push(root);
      while(!q.empty()){
          int k = q.size();
          BinaryTreeNode< int > *temp = NULL;
          for(int i =1;i<=k;i++){
              root= q.front();
              q.pop();
              if(i==1)temp= root;
              else{
                  temp->next =root;
                  temp = root;
              }
              
              if(root->left)q.push(root->left);
              if(root->right)q.push(root->right);
          }
      }  
    
    
    // Write your code here.
}


//If we given complete binary tree
Node* connect(Node* root) {
        if(!root)return NULL;
        //if (root == NULL) return;
        Node *pre = root;
        Node *cur = NULL;
        while(pre->left) {
            cur = pre;
            while(cur) {
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }
