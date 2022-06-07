#include <bits/stdc++.h> 
long long merge(long long *arr,long long left,long long mid,long long right, long long temp[]){
    long long i = left,j = mid,k= left ,ans = 0;
    while(i<=mid-1 and j<=right){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
            ans+= (mid-i);
        }
    }
    while(i<=mid-1) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];
    for(int i =left;i<=right;i++){
        arr[i] = temp[i];
    }
    return ans;
}
long long mergesort(long long *arr,long long left,long long right,long long temp[]){
    long long ans = 0,mid;
    if(right>left){
        mid = (left+right)/2;
        ans += mergesort(arr,left,mid,temp);
        ans+=mergesort(arr,mid+1,right,temp);
        ans+=merge(arr,left,mid+1,right,temp);
    }
    return ans;
}
long long getInversions(long long *arr, int n){
    long long left  = 0,right = n-1;
    long long temp[n];
    return mergesort(arr,left,right,temp);
    // Write your code here.
}
