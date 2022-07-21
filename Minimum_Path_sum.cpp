class Solution {
public:
    int solve(int i ,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 or j<0)return 1e9;
        if(i==0 and j==0) return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0)up+=dp[i-1][j];
                    else up+=1e9;
                    
                    int left = grid[i][j];
                    if(j>0)left+=dp[i][j-1];
                    else left+=1e9;
                    
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
//
int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>prev(m,0),curr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j==0) curr[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0)up+=prev[j];
                    else up+=1e9;
                    
                    int left = grid[i][j];
                    if(j>0)left+=curr[j-1];
                    else left+=1e9;
                    
                    curr[j] = min(up,left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
