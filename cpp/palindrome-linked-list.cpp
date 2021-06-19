/* Problem url: https://leetcode.com/problems/palindrome-linked-list
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
    bool isPalindrome(ListNode* head) {
        int length = 0;
        for (ListNode* node = head; node; node = node->next, ++ length) { }
        ListNode* node = head;
        for (int i = 0; i < (length + 1) / 2; ++ i, node = node->next) { }
        ListNode* prev = NULL;
        for (int i = 0; i < length / 2; ++ i) {
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        node = prev;
        for (int i = 0; i < length / 2; ++ i) {
            if (node->val != head->val) {
                return false;
            }    
            node = node->next;
            head = head->next;
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
