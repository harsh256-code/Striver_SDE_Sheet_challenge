#include<bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    int prefix = 1,suffix = 1;
    int ans = arr[0];
    for(int i =0;i<n;i++){
        if(prefix==0)prefix = 1;
        if(suffix==0) suffix = 1;
        prefix*=arr[i];
        suffix*=arr[n-i-1];
        ans = max({ans,suffix,prefix});
    }
    return ans;
	// Write your code here
}
