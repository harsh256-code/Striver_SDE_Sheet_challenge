/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* root){
    return !root->left and !root->right;
}
void leftTree(TreeNode<int>*root,vector<int>&ans){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isLeaf(curr))ans.push_back(curr->data);
        if(curr->left)curr = curr->left;
        else curr = curr->right;
    }
}
void rightTree(TreeNode<int>*root,vector<int>&ans){
    TreeNode<int>* curr = root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right)curr = curr->right;
        else curr = curr->left;
    }
    for(int i = temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}
void leaf(TreeNode<int>*root,vector<int>&ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left)leaf(root->left,ans);
    if(root->right) leaf(root->right,ans);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!root)return ans;
    if(!isLeaf(root))ans.push_back(root->data);
    leftTree(root,ans);
    leaf(root,ans);
    rightTree(root,ans);
    return ans;
    // Write your code here.
}
