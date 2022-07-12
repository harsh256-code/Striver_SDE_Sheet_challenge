/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *>s;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
        //for(auto it:inorder)cout<<it<<" ";
    }
    
    int next() {
        TreeNode *root = s.top();
        s.pop();
        pushAll(root->right);
        return root->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    void pushAll(TreeNode *root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
