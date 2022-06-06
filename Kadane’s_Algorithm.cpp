class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //if(nums.size() == 1)return nums[0];
        int sum = 0,m=INT_MIN;
        for(auto &it:nums){
            sum+=it;
            m = max(m,sum);
            if(sum<0)sum=0;
            
        }
        return m;
    }
};
