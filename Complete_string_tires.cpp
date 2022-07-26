struct Node {
    Node *links[256];
    bool flag =0;
    
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = 1;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private: Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node *node = root;
        for(auto it:word){
            if(!node->containKey(it)){
                node->put(it,new Node);
            }
            node =node->get(it);
        }
        node->setEnd();
    }
    bool checkAllPrefix(string &word){
        Node *node = root;
        for(auto it:word){
            if(!node->containKey(it))return false;
            
            node = node->get(it);
            if(!node->isEnd())return false;
        }
        return node->isEnd();
    }
};
string completeString(int n, vector<string> &a){
    if(!n)return "";
    Trie trie;
    for(string &it:a){
        trie.insert(it);
    }
    string ans="";
    for(string &word:a){
        if(trie.checkAllPrefix(word)){
            if(word.length()>ans.length()){
                ans = word;
            }else if(word.length()==ans.length() and word<ans){
                ans = word;
            }
        }
    }
    if(ans=="")return "None";
    return ans;
    // Write your code here.
}
