//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool ispalindrome(string s){
        int l=0,h =s.size()-1;
        while(l<=h){
            if(s[l++]!=s[h--])return 0;
        }
        return 1;
    }
    int solve(int i,string &s,vector<int>&dp){
        if(i>=s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        string a="",b;
        for(int j=i;j<s.size();j++){
            a+=s[j];
            b=s[j]+b;
            if(a==b){
                
                 ans = min(ans,1+solve(j+1,s,dp));
            }
           
        }
        return dp[i] = ans;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int>dp(n+1,-1);
        return solve(0,str,dp)-1;
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// Tabulation
int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int>dp(n+1,0);
        for(int i =n-1;i>=0;i--){
            int ans =INT_MAX;
            for(int j=i;j<n;j++){
                if(ispalindrome(i,j,str)){
                    ans = min(ans,1+dp[j+1]);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
        // code here
    }
