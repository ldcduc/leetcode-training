/* Problem url: https://leetcode.com/problems/merge-two-sorted-lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 && l2) {
            if (l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            }
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        } else if (l1) {
            return l1;
        }
        return l2;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
