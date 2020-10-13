/* Problem url: https://leetcode.com/problems/sort-list
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                l3->next = l1;
                l3 = l3->next;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l3 = l3->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            l3->next = l1;
        }
        if (l2) {
            l3->next = l2;
        }
        l3 = head;
        head = head->next;
        delete l3;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (head && head->next) {
            ListNode * fast = head, * slow = head, * prev = NULL; 
            while (fast != NULL && fast->next != NULL) {
                fast = fast->next->next;
                prev = slow;
                slow = slow->next;
            } 
            prev->next = NULL;
            ListNode* l1 = sortList(head);
            ListNode* l2 = sortList(slow);
            return merge(l1, l2); 
        }
        return head;    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list, merge sort
 * 
 * */
