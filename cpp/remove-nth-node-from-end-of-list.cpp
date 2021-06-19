/* Problem url: https://leetcode.com/problems/remove-nth-node-from-end-of-list
 * Code by: ldcduc
 * */
/* Begin of Solution */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recursion(ListNode* node, int& n) {
        if (node) {
            ListNode* nextNode = recursion(node->next, n);
            if (n == 0) {
                ListNode* tmp = node;
                node = node->next;
                delete tmp;
                -- n;
                return node;
            }    
            node->next = nextNode;
        }
        -- n;
        return node;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return recursion(head, n);    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
