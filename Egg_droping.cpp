//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e,int f,vector<vector<int>>&dp){
        if(e==1 or f==0 or f==1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int ans = INT_MAX;
        for(int i =1;i<=f;i++){
            int temp = 1+max(solve(e-1,i-1,dp),solve(e,f-i,dp));
            ans = min(ans,temp);
        }
        return dp[e][f] = ans;
    }
    int eggDrop(int e, int f) 
    {
        vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
        return solve(e,f,dp);
        // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
