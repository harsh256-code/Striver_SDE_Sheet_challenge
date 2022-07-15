#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>ans,vis(vertex,0);
    vector<int>adj[vertex];
    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    for(int i=0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                         q.push(it);
                    }
                   
                }
            }
        }
    }
    return ans;
    
    // Write your code here
}
