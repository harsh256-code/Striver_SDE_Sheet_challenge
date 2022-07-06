/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


bool helper(TreeNode<int>*root,int x, vector<int>&ans){
    if(!root)return false;
    ans.push_back(root->data);
    if(root->data==x)return true;
    
    if(helper(root->left,x,ans) or helper(root->right,x,ans))return true;
    ans.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int>ans;
    if(!root)return ans;
    helper(root,x,ans);
    return ans;
    // Write your code here.
}
