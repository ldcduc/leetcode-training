/* Problem url: https://leetcode.com/problems/lru-cache/
 * Code by: ldcduc
 * */
const bool DEBUG = false;
const int max_value = 100000;
class Node {
public:
    int value, key;
    Node *pprev, *pnext;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        pprev = NULL;
        pnext = NULL;
    } 
};
class LRUCache {
private: 
    int capacity, size_ = 0;
    Node *root = NULL, *tail = NULL;
    Node **link;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size_ = 0;
        root = NULL, tail = NULL;
        link = new Node* [max_value];
        for (int i=0; i<max_value; ++i) 
            link[i] = NULL;
    }
    
    int get(int key) {
        int value = -1;
        if (link[key] != NULL) {
            value = link[key]->value; 
            Remove(link[key]);
            link[key] = Insert(key, value);
        }
        if (DEBUG) { cout << "[" << key << "] "; Print();}
        return value;
    }
    
    void put(int key, int value) {
        if (link[key] != NULL) {
            link[key] = Remove(link[key]);
        }
        else if (size_ == capacity) {
            int root_key = root->key;
            link[root_key] = Remove(root); 
        } 
        link[key] = Insert(key, value);
        if (DEBUG) { cout << '[' << key << ',' << value << "] "; Print();}
    }
    
    Node* Remove(Node *node) {
        if (size_ == 1) {
            delete root; 
            root = tail = NULL; 
        } 
        else if (node == root) {
            root = root->pnext;
            delete root->pprev;
        } else if (node == tail) {
            tail = tail->pprev;
            delete tail->pnext;
        } else {
            node->pprev->pnext = node->pnext;
            node->pnext->pprev = node->pprev;
            delete node;
        }
        --size_;
        return NULL;
    }
    
    Node* Insert(int key, int value) {
        Node *cur = new Node(key, value); 
        if (tail == NULL) {
            root = tail = cur;
        } else {
            tail->pnext = cur;
            cur->pprev = tail;
            tail = cur;
        }
        ++size_;
        return cur;
    }
    ~LRUCache() {
        Node* cur;
        while (root != NULL) {
            cur = root;
            root = root->pnext;
            delete cur;
        }
        delete [] link; 
    }
    
    void Print() {
        Node *cur = root;
        while (cur != NULL) {
            cout << cur->key << ':' << cur->value << "->";
            cur = cur->pnext;
        }
        if (root != NULL) cout << "root " << root->key << ':' << root->value << ' ';
        else cout << "root NULL ";
        if (tail != NULL) cout << "tail " << tail->key << ':' << tail->value << ' ';
        else cout << "tail NULL ";
        cout << '\n';
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */





/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * Becareful of using dynamic allocated memory
 * */
