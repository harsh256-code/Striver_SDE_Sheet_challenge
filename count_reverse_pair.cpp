class Solution {
    private:
    int merge(vector<int>&nums,int low,int mid,int high){
        int cnt = 0;
        int j = mid+1;
        for(int i = low;i<=mid;i++){
            while(j<=high and nums[i] > 2LL*nums[j]){
                j++;
            }
            cnt+= (j-(mid+1));
        }
        int i = low;
        j= mid+1;
        vector<int>temp;
        while(i<=mid and j<=high){
            if(nums[i]<=nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i<=mid) temp.push_back(nums[i++]);
        while(j<=high) temp.push_back(nums[j++]);
        for(int i = low;i<=high;i++){
            nums[i] = temp[i-low];
        }
        return cnt;
    }
    int mergesort(vector<int>&nums,int low,int high){
        if(low>=high) return 0;
        int mid = (low+high) >>1;
        int cnt = mergesort(nums,low,mid);
        cnt+= mergesort(nums,mid+1,high);
        cnt += merge(nums,low,mid,high);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};
