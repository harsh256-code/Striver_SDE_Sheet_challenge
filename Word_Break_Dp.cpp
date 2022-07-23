#include<bits/stdc++.h>
int solve(unordered_map<string,int>&dp,vector<string>&arr,string s){
    if(s.size()==0)return 1;
    if(dp[s]!=0)return dp[s];
    int n =s.size();
    for(int i=1;i<=s.size();i++){
        int f=0;
        string temp = s.substr(0,i);
        for(int j=0;j<arr.size();j++){
            if(temp.compare(arr[j])==0){
                f=1;
                break;
            }
            
        }
        if(f and solve(dp,arr,s.substr(i,n-i))==1) return dp[s]=1;
    }
    return dp[s] = -1;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_map<string,int>dp;
    
    return solve(dp,arr,target)==1?1:0;
    // Write your code here.
}
