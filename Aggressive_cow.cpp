bool ispossible(vector<int>p,int n,int mid,int c){
    int prevplace = p[0];
    int cnt = 1;
    for(int i  = 1;i<n;i++){
        if(p[i]-prevplace>=mid){
            cnt++;
            prevplace  = p[i];
        }
    }
    if(cnt>=c)return true;
    return false;
}
int chessTournament(vector<int> p , int n ,  int c){
    sort(p.begin(),p.end());
    int low = 1,high = p[n-1]-p[0];
    while(low<=high){
        int mid  = (low+high)>>1;
        if(ispossible(p,n,mid,c)) low = mid+1;
        else high = mid-1;
    }
    
    return high;
	// Write your code here
}
