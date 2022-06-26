#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i = 2*n-1;i>=0;i--){
        while(!s.empty() and s.top()<=arr[i%n]){
            s.pop();
        }
        if(!s.empty()){
            ans[i] = s.top();
        }
        s.push(arr[i%n]);
    }
    return ans;
    // Write your code here

}
