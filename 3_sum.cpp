class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        int n  = nums.size();
        for(int i = 0;i<n-2;i++){
            if(i==0 or (i>0 and nums[i]!=nums[i-1])){
                int lo = i+1,hi = n-1,sum = 0-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi] == sum){
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        ans.push_back(temp);
                        
                        while(lo<hi and nums[lo]==nums[lo+1]) lo++;
                        while(lo<hi and nums[hi] == nums[hi-1]) hi--;
                        lo++;
                        hi--;
                    }else if(nums[lo]+nums[hi]>sum)hi--;
                    else lo++;
                }
            }
            
            
            
        }
        return ans;
    }
};
