/* Problem url: https://leetcode.com/problems/design-hashset/
 * Code by: ldcduc
 * */
class MyHashSet {
public:
    /** Initialize your data structure here. */
    int *data;
    MyHashSet() {
        data = (int *)calloc(1000001, sizeof(int));
    }

    void add(int key) {
        data[key] = 1;
    }

    void remove(int key) {
        data[key]--;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return (data[key] > 0);
    }

    ~MyHashSet() {
        free(data);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
