//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int solve(int ind,int prev,int arr[],int n, vector<vector<int>>&dp){
	    if(ind==n)return 0;
	    if(dp[ind][prev+1]!= -1)return dp[ind][prev+1];
	    int sum = solve(ind+1,prev,arr,n,dp);
	    if(prev== -1 or arr[ind]>arr[prev]){
	        sum = max(sum,arr[ind]+solve(ind+1,ind,arr,n,dp));
	    }
	    return dp[ind][prev+1] =  sum;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>dp(n);
	    int ans = arr[0];
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++){
	        dp[i] = arr[i];
	        int temp = INT_MIN;
	        for(int j = 0;j<i;j++){
	            if(arr[i]>arr[j]){
	                if(arr[i]+dp[j]>temp){
	                    temp = arr[i]+dp[j];
	                    dp[i] = temp;
	                }
	            }
	        }
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	    // Your code goes here
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
