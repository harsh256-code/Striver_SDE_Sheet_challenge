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

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int  i = n-- + m-- -1;
        while(n>=0){
            if(m == -1 or nums2[n]>=nums1[m]) nums1[i--] = nums2[n--];
            else nums1[i--] = nums1[m--];
        }
    }
};

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap = ceil((float)(n+m)/2);
            while(gap>0){
                int i = 0;
                int j = gap;
                while(j<(n+m)){
                    if(j<n and arr1[i]>arr1[j]) swap(arr1[i],arr1[j]);
                    else if(j>=n and i<n and arr1[i]>arr2[j-n]) swap(arr1[i],arr2[j-n]);
                    else if(j>=n and i>=n and arr2[i-n]> arr2[j-n]) swap(arr2[i-n],arr2[j-n]);
                    
                    j++;
                    i++;
                }
                if(gap == 1){
                    gap = 0;
                }else {
                    gap = ceil((float)gap/2);
                }
            }
            // code here 
        } 
};

