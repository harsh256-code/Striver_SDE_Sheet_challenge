struct Node{
     Node *links[26];
    Node *get(char ch){
        return links[ch-'a'];
    }
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
};
int distinctSubstring(string &word) {
    int ans=0;
    int n = word.size();
    Node *root = new Node();
    for(int i=0;i<n;i++){
        Node *node = root;
        for(int j=i;j<n;j++){
            if(!node->containKey(word[j])){
                node->put(word[j],new Node);
                ans++;
            }
            node = node->get(word[j]);
        }
    }
    return ans;
    //  Write your code here.
}
