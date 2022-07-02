#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int>ps(n,-1);
    stack<int>s;
    for(int i = 0;i<n;i++){
        while(!s.empty() and a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()) ps[i] = s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    
    vector<int>ns(n,n);
    for(int i = n-1;i>=0;i--){
        while(!s.empty() and a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()) ns[i] = s.top();
        s.push(i);
    }
    vector<int>ans(n,INT_MIN);
    for(int i = 0;i<n;i++){
        int l = (ns[i]-ps[i]-1)-1;
        ans[l] = max(ans[l],a[i]);
    }
    for(int i= n-2;i>=0;i--){
        if(ans[i]<ans[i+1]){
            ans[i] = ans[i+1];
        }
    }
    return ans;
    
    
    // Write your code here.
}
