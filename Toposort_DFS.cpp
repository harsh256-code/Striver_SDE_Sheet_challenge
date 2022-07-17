#include<bits/stdc++.h>
void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&s){
    vis[node] = 1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>adj[v];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    stack<int>s;
    vector<int>ans,indegree(v,0),vis(v,0);
    for(int i =0;i<v;i++){
        if(!vis[i]) dfs(i,adj,vis,s);
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
//     for(int i =0;i<v;i++){
//         for(auto it:adj[i]){
//             indegree[it]++;
//         }
//     }
//     queue<int>q;
//     for(int i =0;i<v;i++){
//         if(indegree[i]==0)q.push(i);
//     }
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         ans.push_back(node);
//         for(auto it:adj[node]){
//             indegree[it]--;
//             if(indegree[it]==0)q.push(it);
//         }
//     }
    return ans;
    // Write your code here
}
