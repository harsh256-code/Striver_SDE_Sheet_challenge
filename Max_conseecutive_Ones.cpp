class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int m = 0;
        for(auto &it:nums){
            if(it==1)m++;
            else m = 0;
            ans = max(ans,m);
        }
        return ans;
    }
};
