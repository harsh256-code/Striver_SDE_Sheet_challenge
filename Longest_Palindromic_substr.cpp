string longestPalinSubstring(string str)
{
    int n =str.size();
    int ans = 1;
    int start = 0;
    for(int i = 0;i<n;i++){
        int r = i;
        while(r<n and str[i]==str[r])r++;
        int l = i-1;
        while(l>=0 and r<n and str[l]==str[r]){
            r++;
            l--;
        }
        int current_l = r-l-1;
        if(current_l>ans){
            ans = current_l;
            start = l+1;
        }
    }
    return str.substr(start,ans);
    // Write your code here.
}
