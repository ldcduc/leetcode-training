/* Problem url: https://leetcode.com/problems/add-two-numbers-ii
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> S[2];
        while (l1) {
            S[0].push(l1);
            l1 = l1->next;
        }
        while (l2) {
            S[1].push(l2);
            l2 = l2->next;
        }
        int remain = 0;
        ListNode* head, * node = NULL;
        while (!S[0].empty() && !S[1].empty()) {
            remain += S[0].top()->val + S[1].top()->val;
            S[0].pop();
            S[1].pop();
            head = new ListNode(remain % 10);
            head->next = node;
            node = head;
            remain /= 10;
        }
        int index = S[0].empty() ? 1 : 0;
        while (!S[index].empty()) {
            remain += S[index].top()->val;
            S[index].pop();
            head = new ListNode(remain % 10);
            head->next = node;
            node = head;
            remain /= 10;
        }
        if (remain) {
            head = new ListNode(remain % 10);
            head->next = node;
        }
        return head;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list, stack
 * 
 * */
