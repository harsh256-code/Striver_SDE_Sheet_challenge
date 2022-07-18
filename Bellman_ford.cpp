int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<long long>ans(n+1,1e9);
    ans[src] = 0;
    for(int i =0;i<n;i++){
        for(auto it:edges){
            int u = it[0];
            int v= it[1];
            int wt = it[2];
            if(ans[u]!=1e9){
                ans[v] = min(ans[v],ans[u]+wt);
            }
            
        }
    }
    return ans[dest];
    // Write your code here.
}
