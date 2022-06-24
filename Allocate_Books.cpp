bool ispossible(vector<int>&A,int mid,int B){
    int cnt = 0;
    int sum = 0;
    for(int i =0;i<A.size();i++){
        if(sum+A[i]>mid){
            cnt++;
            sum = A[i];
            if(sum>mid)return false;
        }else {
            sum+=A[i];
        }
    }
    if(cnt<B)return true;
    return false;
}
int Solution::books(vector<int> &A, int B) {
    if(B>A.size())return -1;
    
    int low = A[0];
    int high = 0;
    for(auto &it:A){
        high+=it;
        low = min(low,it);
    }
    while(low<=high){
        int mid = (low+high)>>1;
        
        if(ispossible(A,mid,B)) high  = mid-1;
        else low = mid+1;
    }
    return low;
}
