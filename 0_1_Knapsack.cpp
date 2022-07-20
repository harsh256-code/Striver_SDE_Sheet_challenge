#include<bits/stdc++.h>
int solve(int n,int w,vector<int>&values,vector<int>&weights,vector<vector<int>>&dp){
    if(n==0){
        if(weights[n]<=w){
            return values[n];
        }
        return 0;
    }
    if(dp[n][w]!=-1)return dp[n][w];
    int notTake = solve(n-1,w,values,weights,dp);
    int take = INT_MIN;
    if(weights[n]<=w){
        take = values[n]+ solve(n-1,w-weights[n],values,weights,dp);
    }
    return dp[n][w] = max(take,notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i =weights[0];i<=w;i++){
        dp[0][i] = values[0];
    }
    for(int i =1;i<n;i++){
        for(int j  =0;j<=w;j++){
            int nt = dp[i-1][j];
            int take = INT_MIN;
            if(weights[i]<=j){
                take = values[i]+ dp[i-1][j-weights[i]];
            }
            dp[i][j] = max(take,nt);
        }
    }
    return dp[n-1][w];
	// Write your code here
}
