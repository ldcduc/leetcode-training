/* Problem url: https://leetcode.com/problems/rotate-list
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* node = head, * prev, * result = head;
        if (node) {
            int length = 0;
            for (; node; ++ length, node = node->next) { }
            k %= length;

            if (k > 0) {
                node = head;
                prev = NULL;
                for (int i = 0; i < length - k; ++ i, node = node->next) {
                    prev = node;
                }

                prev->next = NULL;
                result = node;
                for (; node; node = node->next) {
                    prev = node;
                }
                prev->next = head;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
