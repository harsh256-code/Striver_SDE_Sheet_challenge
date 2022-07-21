#include<bits/stdc++.h>
long solve(int i,int target,int *arr,vector<vector<long>>&dp){
    if(i==0){
        return (target%arr[0]==0);
    }
    if(dp[i][target]!=-1)return dp[i][target];
    long nt = solve(i-1,target,arr,dp);
    long take = 0;
    if(arr[i]<=target){
        take = solve(i,target-arr[i],arr,dp);
    }
    return dp[i][target] = take+nt;
}
long countWaysToMakeChange(int *arr, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,0));
    for(int i=0;i<=value;i++){
        if(i%arr[0]==0){
            dp[0][i] = 1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j =0;j<=value;j++){
            long nt= dp[i-1][j];
            long t=0;
            if(arr[i]<=j){
                t  = dp[i][j-arr[i]];
            }
            dp[i][j] = nt+t;
        }
    }
    return dp[n-1][value];
    //Write your code here
}
