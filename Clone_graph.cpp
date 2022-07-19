/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
// graphNode *dfs(graphNode *n,unordered_map<graphNode *,graphNode*>&mpp){
//     mpp[n] = new graphNode(n->data);
//     vector<graphNode*>v;
//     for(auto it:n->neighbours){
//         if(mpp.find(it)!=mpp.end()){
//             v.push_back(it);
//         }else{
//             v.push_back(dfs(it,mpp));
//         }
//     }
//     n->neighbours = v;
//     return n;
// }
void dfs(graphNode *node,graphNode* root,vector<graphNode*>&vis){
    for(auto it:node->neighbours){
        
        if(!vis[it->data]){
            graphNode *newNode = new graphNode(it->data);
            vis[it->data] = newNode;
            (root->neighbours).push_back(newNode);
            dfs(it,newNode,vis);
        }else {
            (root->neighbours).push_back(vis[it->data]);
        }
    }
}
graphNode *cloneGraph(graphNode *node)
{
    if(!node)return NULL;
    vector<graphNode*>vis(1e5+5,0);
    graphNode* root = new graphNode(node->data);
    vis[node->data] = root;
    dfs(node,root,vis);
    return root;
    // Write your code here.
}
