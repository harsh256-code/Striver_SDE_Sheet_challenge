#include<bits/stdc++.h>
int compareVersions(string a, string b) 
{
   int i=0,j=0,n=a.size(),m=b.size();
    while(i<n or j<m){
        long long n1=0,n2=0;
        while(i<n and a[i]!='.'){
            n1 = n1*10 + 1ll*(a[i]-'0');
            i++;
        }
        while(j<m and b[j]!='.'){
            n2 = n2*10 + 1ll*(b[j]-'0');
            j++;
        }
        if(n1<n2)return -1;
        if(n1>n2)return 1;
        i++;
        j++;
    }
//     if(n>m)return 1;
//     if(n<m)return -1;
    
    return 0;
    // Write your code here
}
