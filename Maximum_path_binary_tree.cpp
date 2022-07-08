/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int solve(TreeNode<int>*root,long long int &ans){
    if(!root)return 0;
    long long int lh = solve(root->left,ans);
    long long int rh = solve(root->right,ans);
    ans = max(ans,lh+rh+root->val);
    return max(lh,rh)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if(!root)return -1;
    if(!root->left or !root->right)return -1;
    long long int ans = 0;
    solve(root,ans);
    
    return ans;
    // Write your code here.
}
