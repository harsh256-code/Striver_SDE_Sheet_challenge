class Solution {
public:
    int solve(int n ,int m,string &w1,string &w2,vector<vector<int>>&dp){
        if(n<0)return m+1;
        if(m<0) return n+1;
        if(dp[n][m]!=-1)return dp[n][m];
        if(w1[n]==w2[m]) return solve(n-1,m-1,w1,w2,dp);
        
        return dp[n][m] =  min({1+solve(n,m-1,w1,w2,dp),1+solve(n-1,m,w1,w2,dp),1+solve(n-1,m-1,w1,w2,dp)});
    }
    int minDistance(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i =0;i<=n;i++){
            dp[i][0] = i;
        }
        for(int j = 0;j<=m;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};
//Space Optimization
int minDistance(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j = 0;j<=m;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j = 1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                    curr[j] = 1+min(prev[j-1],min(prev[j],curr[j-1]));
                }
            }
            prev = curr;
        }
        return prev[m];
    }
