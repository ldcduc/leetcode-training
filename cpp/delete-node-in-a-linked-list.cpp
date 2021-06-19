/* Problem url: https://leetcode.com/problems/delete-node-in-a-linked-list
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
    void deleteNode(ListNode* node) {
        ListNode* next;
        next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
