#include<bits/stdc++.h>
class Kthlargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int K;
public:
    Kthlargest(int k, vector<int> &arr) {
        K = k;
        for(auto it:arr){
            pq.push(it);
            if(pq.size()>k)pq.pop();
        }
       // Write your code here.
    }

    void add(int num) {
        pq.push(num);
        if(pq.size()>K)pq.pop();
        // Write your code here.
    }

    int getKthLargest() {
        return pq.top();
       // Write your code here.
    }

};
