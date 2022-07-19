#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>>adj[n+1];
    for(auto it:g){
        adj[it.first.first].push_back({it.first.second,it.second});
        adj[it.first.second].push_back({it.first.first,it.second});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>mst(n+1,0),parent(n+1,-1),key(n+1,INT_MAX);
    pq.push({0,1});
    key[1] = 0;
    parent[1] =-1;
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        mst[u] = 1;
        for(auto it:adj[u]){
            int v = it.first;
            int wt = it.second;
            if(mst[v]==0 and wt<key[v]){
                parent[v] = u;
                key[v] = wt;
                pq.push({wt,v});
            }
        }
    }
    vector<pair<pair<int,int>,int>>ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
    // Write your code here.
}
