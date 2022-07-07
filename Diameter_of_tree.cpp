/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(TreeNode<int>*root,int &d){
    if(!root)return  0;
    int lh = height(root->left,d);
    int rh = height(root->right,d);
    d = max(d,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    int d =0;
    height(root,d);
    return d;
	// Write Your Code Here.
}
