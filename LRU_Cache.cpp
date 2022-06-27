class LRUCache {
    class node{
        public:
        int key;
        int val;
        node *next,*prev;
        node(int _key,int _val){
            key= _key;
            val = _val;
        }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *newnode){
        node *nextn = head->next;
        head->next = newnode;
        nextn->prev = newnode;
        newnode->next = nextn;
        newnode->prev= head;
    }
    void deletenode(node *delnode){
        node *nexn = delnode->next;
        node *prevn = delnode->prev;
        prevn->next = nexn;
        nexn->prev = prevn;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            node *resnode = m[key];
            int resval = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return resval;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            node *n = m[key];
            m.erase(key);
            deletenode(n);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
