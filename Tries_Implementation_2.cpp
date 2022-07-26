struct Node{
    Node *links[26];
    int cntEndWith =0;
    int cntPrefix =0;
    
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
   
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
     int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
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
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node);
            
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(auto it:word){
            if(node->containKey(it)){
                node = node->get(it);
            }else return 0;
        }
        return node->getEnd();
        // Write your code here.
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(auto it:word){
            if(node->containKey(it)){
                node = node->get(it);
            }else return 0;
        }
        return node->getPrefix();
        // Write your code here.
    }

    void erase(string &word){
        Node *node = root;
        for(auto it:word){
            if(node->containKey(it)){
                node = node->get(it);
                node->reducePrefix();
            }else return;
        }
        node->deleteEnd();
        // Write your code here.
    }
};
