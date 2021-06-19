/* Problem url: https://leetcode.com/problems/remove-duplicates-from-sorted-list
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
        ListNode* node = head;
        ListNode* prev_node = NULL;
        if (head) {
            prev_node = head;
            node = head->next;
        }
        while (node) {
            if (node->val == prev_node->val) {
                // Need to delete this node
                ListNode* next_node = node->next;
                prev_node->next = next_node; 
                delete node;
                node = next_node;
            } else {
                prev_node = node;
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
