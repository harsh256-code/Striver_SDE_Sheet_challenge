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

//if we allowed to change k zero to one the what is the value of max ones
int longestSubSeg(vector<int> &arr , int n, int k){
    int cz= 0;
    int ans = 0;
    int j =0;
    for(int i = 0;i<n;i++){
        if(arr[i]==0)cz++;
        while(cz>k){
            if(arr[j]==0)cz--;
            j++;
        }
        ans = max(ans,(i-j)+1);
    }
    return ans;
    // Write your code here.
}
