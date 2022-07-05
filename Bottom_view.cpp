/*************************************************************
 
    Following is the Binary Tree node structure.

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

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int>ans;
    if(!root)return ans;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    map<int,int>m;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        root = it.first;
        int line = it.second;
        m[line] = root->data;
        
        if(root->left){
            q.push({root->left,line-1});
        }
        if(root->right) q.push({root->right,line+1});
    }
    
    for(auto it:m)ans.push_back(it.second);
    
    
    return ans;
    // Write your code here.
    
}
