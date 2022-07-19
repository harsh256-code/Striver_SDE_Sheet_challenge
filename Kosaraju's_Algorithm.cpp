#include<bits/stdc++.h>
void dfs(int node,vector<int>&vis,vector<int>adj[],stack<int>&s){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,s);
        }
    }
    s.push(node);
}
void revDfs(int node,vector<int>&vis,vector<int>tadj[],vector<int>&temp){
    temp.push_back(node);
    vis[node] = 1;
    for(auto it:tadj[node]){
        if(!vis[it]){
            revDfs(it,vis,tadj,temp);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int>adj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    stack<int>s;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,s);
        }
    }
    vector<int>tadj[n];
    for(int i=0;i<n;i++){
        vis[i] = 0;
        for(auto it:adj[i]){
            tadj[it].push_back(i);
        }
    }
    vector<vector<int>>ans;
    while(!s.empty()){
        int node = s.top();
        s.pop();
            vector<int>temp;
            if(!vis[node]){
                revDfs(node,vis,tadj,temp);  
            }
            ans.push_back(temp);
    }
    return ans;
    // Write your code here.
}
