#include<bits/stdc++.h>
bool comp(pair<int,int>&a,pair<int,int> &b){
    return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int,int>>a(n);
    for(int i = 0;i<n;i++){
        a[i]= {start[i],finish[i]};
    }
    sort(a.begin(),a.end(),comp);
    int ans = 1;
    int limit = a[0].second;
    for(int i = 1;i<n;i++){
        if(a[i].first>=limit){
            ans++;
            limit = a[i].second;
        }
    }
    return ans;
    // Write your code here.
}
