#include<bits/stdc++.h>
struct node{
  int u,v,wt;
    node(int _u,int _v,int _wt){
        u=_u;
        v = _v;
        wt = _wt;
    }
};
bool comp(node a,node b){
    return a.wt<b.wt;
}
int findpar(int u,vector<int>&parent){
    if(u==parent[u])return u;
    return parent[u] = findpar(parent[u],parent);
}
void unionRank(int u,int v,vector<int>&parent,vector<int>&rank){
    u = findpar(u,parent);
    v = findpar(v,parent);
    if(rank[u]<rank[v]){
        parent[u] = v;
    }else if(rank[v]<rank[u]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    vector<node>adj;
    for(auto it:graph){
        int u = it[0],v = it[1],wt= it[2];
        adj.push_back(node(u,v,wt));
    }
    sort(adj.begin(),adj.end(),comp);
    int cost =0;
    vector<int>parent(n+1),rank(n+1,0);
    for(int i =0;i<=n;i++){
        parent[i] = i;
    }
    for(auto it:adj){
        if(findpar(it.v,parent)!= findpar(it.u,parent)){
            cost+=it.wt;
            unionRank(it.u,it.v,parent,rank);
        }
    }
    return cost;
	// Write your code here.
}
