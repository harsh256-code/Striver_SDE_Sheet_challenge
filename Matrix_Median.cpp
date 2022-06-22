int countN(vector<int>&row,int x){
    int  l = 0,h = row.size()-1;
    while(l<=h){
        int mid = (l+h)>>1;
        if(row[mid]<=x)l = mid+1;
        else h = mid-1;
    }
    return l;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while(low<=high){
        int mid = (low+high)>>1;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt+= countN(A[i],mid);
        }
        
        if(cnt<=(m*n)/2)low =mid+1;
        else high = mid-1;
    }
    return low;
}

