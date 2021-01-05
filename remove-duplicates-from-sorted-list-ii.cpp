/* Problem url: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
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
class RecursiveSolution {
public:
    ListNode* recursion(ListNode* node, int last_val) {
        if (node) {
            if (node->next && node->val == node->next->val) {
                last_val = node->val;
            }
            node->next = recursion(node->next, node->val);
            if (node->val == last_val) {
                ListNode* tmp = node;
                node = node->next;
                delete tmp;
            }
        }
        return node;
    } 
    ListNode* deleteDuplicates(ListNode* head) {
        return recursion(head, -100 - 1);    
    }
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int last_val = -100 - 1;
        ListNode* prev = NULL;
        ListNode* node = head;
        while (node) {
            if (node->next && node->next->val == node->val) {
                last_val = node->val;
            }
            if (last_val == node->val) { // This node need to be deleted
                if (head == node) {
                    head = node->next;
                    delete node;
                    node = head;
                } else {
                    ListNode* tmp = node;
                    node = node->next;
                    delete tmp;
                    if (prev != NULL) {
                        prev->next = node;
                    }
                }
            } else {
                prev = node;
                node = node->next;
            }
        }
        return head;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
