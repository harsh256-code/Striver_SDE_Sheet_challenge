class Solution {
public:
    int solve(int n,int m,string &s1,string &s2,vector<vector<int>>&dp){
        if(n< 0 or m<0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        if(s1[n]==s2[m]){
            return dp[n][m] = 1+solve(n-1,m-1,s1,s2,dp);
        }
        return dp[n][m] = max(solve(n-1,m,s1,s2,dp),solve(n,m-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(curr[j-1],prev[j]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};
