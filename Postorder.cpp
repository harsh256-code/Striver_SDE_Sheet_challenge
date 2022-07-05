/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>ans;
    if(!root)return ans;
    stack<TreeNode*>s;
    while(root or !s.empty()){
        if(root){
            s.push(root);
            root = root->left;
        }else{
            TreeNode *temp = s.top()->right;
            if(temp==NULL){
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty() and temp==s.top()->right){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }else root = temp;
        }
    }
    return ans;
    // Write your code here.
}

// Recursive Approach
void helper(TreeNode *root,vector<int>&ans){
        if(!root)return;
        helper(root->left,ans);
        helper(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        helper(root,ans);
        return ans;
    }
