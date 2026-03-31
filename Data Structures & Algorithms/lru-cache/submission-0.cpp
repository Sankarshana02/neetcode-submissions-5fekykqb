class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k , int v): key(k), val(v), prev(nullptr),next(nullptr){}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*>mpp;
    Node*left;
    Node* right;

    void remove(Node* node){
        Node* prev=node->prev;
        Node* nxt=node->next;
        prev->next=nxt;
        nxt->prev=prev;
    }

    void insert(Node* node){
        Node* prev=right->prev;
        prev->next=node;
        node->prev=prev;
        node->next=right;
        right->prev=node;
    }
public:
    
    LRUCache(int capacity) {
        cap=capacity;
        mpp.clear();
        left=new Node(0,0);
        right= new Node(0,0);
        left->next=right;
        right->prev=left;
        
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            remove(mpp[key]);
        }
        
        Node* newNode= new Node(key,value);
        mpp[key]=newNode;
        insert(newNode);
        if(mpp.size()>cap){
            Node* lru=left->next;
            remove(lru);
            mpp.erase(lru->key);
            delete lru;
        }
    }
};
