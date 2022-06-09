int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>m;
    int c = 0;
    int crr= 0;
    for(auto &it:A){
        crr^=it;
        if(crr==B)c++;
        int h = crr^B;
        if(m.find(h)!=m.end()){
            c+= m[h];
        }
        m[crr]++;
    }
    return c;
}
