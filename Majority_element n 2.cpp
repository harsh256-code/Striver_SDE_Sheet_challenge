class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c =1,e = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(c==0){
                e= nums[i];
            }
            if(e==nums[i])c++;
            else c--;
        }
        return e;
    }
};

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    int c = 1,e =arr[0];
    for(int i = 1;i<n;i++){
        if(c==0) e = arr[i];
        if(e == arr[i]) c++;
        else c--;
    }
    
    c = 0;
    for(int i = 0;i<n;i++){
        if(arr[i]==e)c++;
    }
    if(c>n/2)return e;
    return -1;
	// Write your code here.
}
