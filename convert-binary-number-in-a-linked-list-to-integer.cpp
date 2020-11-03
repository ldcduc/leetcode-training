/* Problem url: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head) {
            result = (result << 1) ^ head->val;
            head = head->next;
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
