#include<bits/stdc++.h>
bool bfs(int node,vector<int>adj[],vector<int>&vis){
    queue<pair<int,int>>q;
    q.push({node,-1});
    vis[node] = 1;
    while(!q.empty()){
        node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]  =1;
                q.push({it,node});
            }else if(par!=it)return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int>adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n+1,0);
    for(int i =1;i<=n;i++){
        if(!vis[i]){
            if(bfs(i,adj,vis))return "Yes";
        }
    }
    return "No";
    // Write your code here.
}
