#include<bits/stdc++.h>
bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis){
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,dfsvis)) return true;
        }else if(dfsvis[it])return true;
    }
    
    dfsvis[node] =0;
    return false;
}
bool bfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis){
    vis[node] = 1;
    dfsvis[node] =1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(auto it:adj[i]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }else if(dfsvis[it])return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int>adj[n+1];
    for(auto it:edges){
        adj[it.first].push_back(it.second);
    }
    vector<int>vis(n+1,0),dfsvis(n+1,0);
    for(int i =1;i<n;i++){
        if(!vis[i]){
            if(bfs(i,adj,vis,dfsvis))return true;
        }
    }
    return false;
  // Write your code here.
}
