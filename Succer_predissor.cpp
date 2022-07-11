/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    if(!root)return {-1,-1};
    int pre =-1,succ=-1;
    BinaryTreeNode<int>* temp = root;
    while(root){
        if(key>=root->data){
            root = root->right;
        }else {
            succ= root->data;
            root = root->left;
        }
    }
    root = temp;
    while(root){
        if(key<=root->data){
            root = root->left;
        }else{
            pre = root->data;
            root = root->right;
        }
    }
   
    return {pre,succ};
    // Write your code here.
}
