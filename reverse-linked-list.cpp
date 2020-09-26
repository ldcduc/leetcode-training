/* Problem url: https://leetcode.com/problems/reverse-linked-list/
 * Code by: ldcduc
 *
 * */
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
    ListNode* reverseList(ListNode* head) {
        if (head && head->next) {
            ListNode* node = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return node;
        }
        return head;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        } else {
            return solveRecursively(NULL, head);
            // return solveIteratively(head);
        }
    }
    
    ListNode* solveRecursively(ListNode* prev, ListNode* head) {
        ListNode* next = head->next;
        head->next = prev;
        if (next) {
            return solveRecursively(head, next);
        } else {
            return head;
        }
    }
    
    ListNode* solveIteratively(ListNode* head) {
        ListNode* cur = head, * prev = NULL, * next; 
        while (cur != NULL) {
            next = cur->next; 
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */

