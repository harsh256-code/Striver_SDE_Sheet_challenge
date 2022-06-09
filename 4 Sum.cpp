class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        if(nums.empty()) return ans;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j =i+1;j<n;j++){
                int target2 = target - nums[i] - nums[j];
                int front = j+1,back = n-1;
                while(front<back){
                    if(nums[front] + nums[back]<target2) front++;
                    else if(nums[front] + nums[back]>target2) back--;
                    else {
                        vector<int>q(4);
                        q[0] = nums[i];
                        q[1] = nums[j];
                        q[2] = nums[front];
                        q[3] = nums[back];
                        ans.push_back(q);
                        
                        while(front<back and nums[front] == q[2]) front++;
                        while(front<back and nums[back] == q[3])back--;
                        
                    }
                }
                while(j+1<n and nums[j+1] == nums[j]) j++;
                
            }
            while(i+1<n and nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};

#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    //
    unordered_map<int,pair<int,int>>mpp;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            mpp[arr[i]+arr[j]] = {i,j};
        }
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int val = arr[i]+arr[j];
            if(mpp.find(target-val)!= mpp.end()){
                pair<int,int>p = mpp[target-val];
                if((p.first!=i and p.second!=j ) and (p.first!=j and p.second!=i))return "Yes";
            }
        }
    }
        return "No";
    // Write your code here.
}

