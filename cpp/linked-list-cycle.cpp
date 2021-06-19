/* Problem url: https://leetcode.com/problems/linked-list-cycle
 * Code by: ldcduc
 * */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* node1 = head, * node2 = head;
        if (head == NULL) {
            return false;
        }
        while (true) {
            if (node1->next == NULL || node2->next == NULL || node2->next->next == NULL) {
                break;
            }
            node1 = node1->next;
            node2 = node2->next->next;
            if (node1 == node2) {
                return true;
            }
        }
        return false;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: linked list, fun, easy
 * 
 * */
