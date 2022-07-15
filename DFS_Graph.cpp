void dfs(vector<int>adj[],vector<int>&vis,int node,vector<int>&temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(adj,vis,it,temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int>adj[V];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]); //Creating Adj list
        adj[it[1]].push_back(it[0]);
    }
    vector<vector<int>>ans;
    vector<int>vis(V,0);
    for(int i =0;i<V;i++){
        if(!vis[i]){
            vector<int>temp;
            dfs(adj,vis,i,temp);
            ans.push_back(temp);
        }
    }
    return ans;
    // Write your code here
}
