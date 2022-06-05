

class Node{
public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int _key,int _val){
        key = _key;
        val = _val;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>m;
    int capacity;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insert(Node* curr){
        curr->next = head->next;
        head->next->prev = curr;
        
        head->next = curr;
        curr->prev = head;
        
        m[curr->key] = curr;
    }
    
    void remove(Node* curr){
        m.erase(curr->key);
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        
        Node* curr = m[key];
        remove(curr);
        insert(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            remove(m[key]);
        }
        if(m.size()==capacity){
            remove(tail->prev);
        }
        Node* newNode = new Node(key,value);
        insert(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
