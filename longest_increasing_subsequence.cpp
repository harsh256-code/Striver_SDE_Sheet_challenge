class Solution {
public:
    int solve(int ind,int pre_ind,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][pre_ind+1]!=-1)return dp[ind][pre_ind+1];
        int len = solve(ind+1,pre_ind,nums,dp);
        if(pre_ind==-1 or nums[ind]>nums[pre_ind]){
            len = max(len,1+solve(ind+1,ind,nums,dp));
        }
        return dp[ind][pre_ind+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr(n+1,0),next(n+1,0);
        for(int ind = n-1;ind>=0;ind--){
            for(int pre = ind-1;pre>=-1;pre--){
                int len = next[pre+1];
                if(pre==-1 or nums[ind]>nums[pre]){
                    len = max(len,1+next[ind+1]);
                }
                curr[pre+1] = len;
            }
            next = curr;
        }
        return curr[0];
    }
};
// Optimize approach...  SC = O(N)
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int>dp(n,1);
        int maxi = 1;
        for(int ind =0;ind<n;ind++){
            for(int pre= 0;pre<ind;pre++){
                if(nums[pre]<nums[ind]){
                    dp[ind] = max(dp[ind],1+dp[pre]);
                }
            }
            maxi = max(maxi,dp[ind]);
        }
        return maxi;
    }

// For printing LIS...
int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
       vector<int>dp(n,1),hash(n);
        int maxi = 1;
        int last_ind =0;
        for(int ind =0;ind<n;ind++){
            hash[ind] = ind; 
            for(int pre= 0;pre<ind;pre++){
                if(nums[pre]<nums[ind] and 1+dp[pre]>dp[ind]){
                    dp[ind] = 1+dp[pre];
                    hash[ind] = pre;
                }
            }
            if(dp[ind]>maxi){
                maxi = dp[ind];
                last_ind = ind;
            }
        }
        vector<int>ans;
        ans.push_back(nums[last_ind]);
        while(hash[last_ind]!=last_ind){
            last_ind = hash[last_ind];
            ans.push_back(nums[last_ind]);
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans)cout<<it<<" ";
        return maxi;
    }
