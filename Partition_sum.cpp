class Solution {
public:
    bool solve(int i,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(i==0){
            return sum==nums[0];
            
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool nt = solve(i-1,nums,sum,dp);
        bool take =0;
        if(nums[i]<=sum){
            take = solve(i-1,nums,sum-nums[i],dp);
        }
        return dp[i][sum] = (take or nt);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum&1)return 0;
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>((sum/2)+1,-1));
        return solve(n-1,nums,sum/2,dp);
    }
};
 bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum&1)return 0;
        int n = nums.size();
        sum = sum/2;
        //vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        vector<int>prev(sum+1,0);
        prev[0] =1;
        if(nums[0]<=sum){
            prev[nums[0]] = 1;
        }
        for(int i =1;i<n;i++){
            vector<int>curr(sum+1,0);
            curr[0] = 1;
            for(int j=1;j<=sum;j++){
                int nt = prev[j];
                int take =0;
                if(nums[i]<=j){
                    take = prev[j-nums[i]];
                }
                curr[j] = (nt or take);
            }
            prev = curr;
        }
        return prev[sum];
    }
