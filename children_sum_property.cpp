/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void reorder(BinaryTreeNode < int > * root){
    if(!root)return;
    int tot = 0;
    if(root->left)tot+=root->left->data;
    if(root->right)tot+=root->right->data;
    
    if(tot<root->data){
        if(root->left){
            root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }
    reorder(root->left);
    reorder(root->right);
    
    int sum=0;
    if(root->left)sum+=root->left->data;
    if(root->right)sum+=root->right->data;
    if(root->left or root->right)root->data = sum;
    
}
void changeTree(BinaryTreeNode < int > * root) {
    reorder(root);
    // Write your code here.
}  
