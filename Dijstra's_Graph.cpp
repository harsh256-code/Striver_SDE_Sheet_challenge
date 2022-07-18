vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>>adj[vertices];
    for(auto it:vec){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int>ans(vertices,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    ans[source] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        for(auto it:adj[node]){
            int n = it.first;
            int wt = it.second;
            if(ans[n]>dis+wt){
                ans[n] = dis+wt;
                pq.push({dis+wt,n});
            }
        }
    }
    return ans;
    // Write your code here.
}
