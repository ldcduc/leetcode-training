/* Problem url: https://leetcode.com/problems/merge-in-between-linked-lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* node2 = list2;
        while (node2->next) {
            node2 = node2->next;
        }
        ListNode* node1 = list1;
        int index = 0;
        while (node1) {
            if (index == b + 1) {
                node2->next = node1;
                break;
            }
            if (index == a - 1) {
                ListNode* tmp = node1->next;
                node1->next = list2;
                node1 = tmp;
            } else {
                node1 = node1->next;
            }
            ++ index;
        }
        return list1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
