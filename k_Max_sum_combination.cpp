#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    vector<int>ans;
    priority_queue<pair<int,pair<int,int>>>pq;
    set<pair<int,int>>s;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    
    while(k--){
        auto it = pq.top();
        pq.pop();
        ans.push_back(it.first);
        int i = it.second.first;
        int j = it.second.second;
        if(s.find({i,j-1})==s.end()){
            s.insert({i,j-1});
            pq.push({a[i]+b[j-1],{i,j-1}});
        }
        if(s.find({i-1,j})==s.end()){
            s.insert({i-1,j});
            pq.push({a[i-1]+b[j],{i-1,j}});
        }
        
    }
    return ans;
    
	// Write your code here.
}
