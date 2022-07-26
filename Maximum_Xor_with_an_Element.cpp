class Node{
   Node *links[2];
    public:
    void put(int bit,Node *node){
        links[bit] = node;
    }
    Node *get(int bit){
        return links[bit];
    }
    bool containKey(int bit){
        return (links[bit]!=NULL);
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num){
        int ans=0;
        Node *node =root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containKey(!bit)){
                ans = ans | (1<<i);
                node = node->get(!bit);
            }else{
                node = node->get(bit);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>>q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][1],queries[i][0],i});
        }
        Trie trie;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        sort(q.begin(),q.end());
        vector<int>ans(q.size(),0);
        int i=0;
        for(auto it:q){
            //cout<<it[0]<<" "<<it[1]<<" "<<it[2];
            while(i<n and nums[i]<=it[0]){
                trie.insert(nums[i]);
                i++;
            }
            if(i==0)ans[it[2]] = -1;
            else ans[it[2]] = trie.getMax(it[1]);
            
        }
        return ans;
        
    }
};
