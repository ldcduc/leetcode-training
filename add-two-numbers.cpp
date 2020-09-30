/* Problem url: https://leetcode.com/problems/add-two-numbers
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
    void addRemain(ListNode* node, ListNode* prev, int remain) {
        while (node) {
            prev->next = node;
            remain += node->val;
            node->val = remain % 10;
            remain /= 10;
            prev = node;
            node = node->next;
        } 
        if (remain) {
            prev->next = new ListNode(remain);
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *prev;
        int remain = 0;
        while (l1 && l2) {
            remain += l1->val + l2->val;
            ListNode* node = new ListNode(remain % 10);
            remain /= 10;
            if (head) {
                prev->next = node;
            } else {
                head = node;
            }
            prev = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l1) {
            addRemain(l1, prev, remain);
        } else if (l2) {
            addRemain(l2, prev, remain);
        } else if (remain) {
            prev->next = new ListNode(remain);
        }
        return head;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
