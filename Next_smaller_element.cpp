#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i = n-1;i>=0;i--){
        while(!s.empty() and s.top()>=arr[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
    // Write your code here.
}
