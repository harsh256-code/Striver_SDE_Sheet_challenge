#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int set_bit_c;
    int x = 0;
    int y= 0;
    int xor1 = arr[0];
    for(int i = 1;i<n;i++) xor1^=arr[i];
    for(int i = 1;i<=n;i++) xor1^=i;
    set_bit_c = xor1&~(xor1-1);
    
    for(int i = 0;i<n;i++){
        if(set_bit_c&arr[i]) x^=arr[i];
        else y^=arr[i];
    }
    for(int i =1;i<=n;i++){
        if(set_bit_c&i) x^=i;
        else y^=i;
    }
    int c =0;
    for(int i = 0;i<n;i++){
        if(arr[i] == x) c++;
    }
    if(c==0) return {x,y};
    return {y,x};
	// Write your code here 
	
}
