int solve(int ind,int n,vector<int>&p,vector<vector<int>>&dp){
    if(ind==0){
       return n*p[0];
    }
    if(dp[ind][n]!=-1)return dp[ind][n];
    int not_c = solve(ind-1,n,p,dp);
    int len = ind+1;
    int cut= INT_MIN;
    if(len<=n){
        cut = p[ind] +solve(ind,n-len,p,dp);
    }
    return dp[ind][n] = max(not_c,cut);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i =1;i<=n;i++){
        dp[0][i] = price[0]*i;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            int n_c = dp[i-1][j];
            int c = INT_MIN;
            int len = i+1;
            if(len<=j){
                c = price[i] + dp[i][j-len];
            }
            dp[i][j] = max(c,n_c);
        }
    }
    return dp[n-1][n];
	// Write your code here. 
}

// Space Optimazation
int cutRod(vector<int> &price, int n)
{
    vector<int>prev(n+1,0),curr(n+1,0);
    for(int i =1;i<=n;i++){
        prev[i] = price[0]*i;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            int n_c = prev[j];
            int c = INT_MIN;
            int len = i+1;
            if(len<=j){
                c = price[i] + prev[j-len];
            }
           prev[j] = max(c,n_c);
        }
        //prev = curr;
    }
    return prev[n];
	// Write your code here. 
}
