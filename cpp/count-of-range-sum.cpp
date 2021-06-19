/* Problem url: https://leetcode.com/problems/count-of-range-sum
 * Code by: ldcduc
 * */
class Node {
public:
    int val, cnt, sumCnt;
    Node* left, * right;
    Node(int val) {
        this->val = val;
        this->cnt = 1;
        this->sumCnt = 1;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* root;
    int lower, upper;

    Solution() {
        root = NULL;
    }
    void insert(Node* node, int val) {
        if (val == node->val) {
            ++node->cnt;
            ++node->sumCnt;
        } else if (val < node->val) {
            if (node->left) {
                insert(node->left, val);
            } else {
                node->left = new Node(val);
            }
            ++node->sumCnt;
        } else {
            if (node->right) {
                insert(node->right, val);
            } else {
                node->right = new Node(val);
            }
            ++node->sumCnt;
        }
    }
    void insert(int val) {
        if (root == NULL) {
            root = new Node(val);
        } else {
            insert(root, val);
        }
    }
    int countLessThan(Node* node, long long val) {
        if (node) {
            if (node->val < val) {
                int result = node->cnt;
                if (node->left) {
                    result += node->left->sumCnt;
                }
                result += countLessThan(node->right, val);
                return result;
            }
            if (node->val == val) {
                int result = node->left ? node->left->sumCnt : 0;
                return result;
            } else {
                return countLessThan(node->left, val);
            }
        }
        return 0;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int result = 0;
        long long sum = 0;
        this->lower = lower;
        this->upper = upper;
        insert(0);
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            int cnt1 = countLessThan(root, sum - lower + 1);
            int cnt2 = countLessThan(root, sum - upper);
            result += cnt1 - cnt2;
            insert(sum);
        }
        return result;
    }
    void destroy(Node* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
    ~Solution() {
        destroy(root);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search tree
 * 
 * */

