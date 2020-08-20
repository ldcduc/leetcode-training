/* Problem url: https://leetcode.com/problems/implement-trie-prefix-tree
 * Code by: ldcduc
 * */
class TNode {
public:
    TNode* next[26];
    int val;
    TNode() {
        for (int i = 0; i < 26; ++ i) {
            next[i] = NULL;
        }
        val = 0;
    }
};

class Trie {
public:
    TNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TNode* node = root;
        for (auto c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new TNode();
            }
            node = node->next[c - 'a'];
        }
        ++node->val;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TNode* node = root;
        for (auto c : word) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return node->val;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TNode* node = root;
        for (auto c : prefix) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return true;
    }
    void Destruct(TNode* node) {
        if (node) {
            for (int i = 0; i < 26; ++ i) {
                Destruct(node->next[i]);
            }
            delete node;
        }
    }
    ~Trie() {
        Destruct(root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
/*
 * Comment by ldcduc
 * Suggested tags: trie, dynamic memory allocation
 * 
 * */

