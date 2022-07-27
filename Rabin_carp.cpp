#include<bits/stdc++.h>
#define ll long long int
#define prime 1
ll createHash(string &str,int n){
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(ll)(str[i]*(ll)pow(prime,i));
    }
    return ans;
}
ll reCalculateHash(ll oldHash,string str,int oldIndex,int newIndex,int patlength){
    ll newHash = oldHash-str[oldIndex];
    newHash/=prime;
    newHash +=(ll)(str[newIndex]*(ll)pow(prime,patlength-1));
    return newHash;
}
bool checkEqual(string str1,string str2,int start1,int end1,int start2,int end2){
    if(end1-start1!=end2-start2){
        return 0;
    }
    while(start1<=end1 and start2<=end2){
        if(str1[start1]!=str2[start2])return 0;
        start1++;
        start2++;
    }
    return true;
}
vector<int> stringMatch(string &str, string &pat) {
    ll strHash = createHash(str,pat.size());
    ll patHash = createHash(pat,pat.size());
    int n = str.size();
    int m =pat.size();
    vector<int>ans;
    for(int i=0;i<=n-m;i++){
        if(strHash==patHash and checkEqual(str,pat,i,i+m-1,0,m-1)){
            ans.push_back(i);
        }if(i<n-m){
            strHash = reCalculateHash(strHash,str,i,i+m,m);
        }
    }
    return ans;
    // Write your code here
}
