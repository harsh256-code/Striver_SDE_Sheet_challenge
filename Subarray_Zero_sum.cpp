class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto &it:nums)s.insert(it);
        int ans = 0;
        for(auto &it:nums){
            if(!s.count(it-1)){
                int currNum = it;
                int streak = 1;
                while(s.count(currNum+1)){
                    currNum++;
                    streak++;
                }
                ans = max(ans,streak);
            }
        }
        return ans;
    }
};
