#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &a, int n)
{
    int k=n-2,l=n-1;
    for(k=n-2;k>=0;k--){
        if(a[k]<a[k+1])break;
    }
    if(k<0){
        reverse(a.begin(),a.end());
    }else{
        for(l=n-1;l>=0;l--){
            if(a[l]>a[k])break;
        }
        swap(a[k],a[l]);
        reverse(a.begin()+k+1,a.end());
    }
    return a;
    //  Write your code here.
}
