#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    long prefix[n],suffix[n];
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = max(prefix[i-1],arr[i]);
    }
    suffix[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i] = max(suffix[i+1],arr[i]);
    }
    long ans =0;
    for(int i=0;i<n;i++){
        ans+=min(prefix[i],suffix[i])-arr[i];
    }
    return ans;
    // Write your code here.
}
long getTrappedWater(long *a, int n){
    // Write your code here.
    
    long lmax=0,rmax=0;
    
   int i=0,j=n-1;
    long sum=0;
    
    while(i<j){
        lmax=max(lmax,a[i]);
        rmax=max(rmax,a[j]);
            
        if(lmax<rmax){
            sum+=(lmax-a[i]);
            i++;
        }else{
            sum+=(rmax-a[j]);
            j--;
        }
    }
    return sum;
}
