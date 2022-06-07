//With extra space

#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i = 0,j = 0;
    vector<int>ans;
    while(i< m and j < n){
        if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i++]);
        }else if(arr1[i] == arr2[j]){
             ans.push_back(arr1[i++]);
            ans.push_back(arr2[j++]);
        }else ans.push_back(arr2[j++]);
    }
    while(i<m) ans.push_back(arr1[i++]);
    while(j<n) ans.push_back(arr2[j++]);
    return ans;
	// Write your code here.
}
