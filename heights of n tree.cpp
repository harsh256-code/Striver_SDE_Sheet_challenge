void dfs(int node,vector<int>adj[],vector<int>&height,vector<int>&vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                height[it] = 1+height[node];
                dfs(it,adj,height,vis);
            }
        }
    }
int optimalValue(int n, int x, vector<int> &p) {
        // code here
        vector<int>adj[n+1];
        int root=-1;
        for(int i=0;i<n;i++){
            if(p[i]==-1)root = i+1;
            else {
                adj[p[i]].push_back(i+1);
            }
            
        }
        vector<int>vis(n+1,0);
        vector<int>height(n+1,0);
        height[root] =1;
        dfs(root,adj,height,vis);
        int h = *max_element(height.begin(),height.end());
        int ans =( x+h-1)/h;
        return ans;
    }
