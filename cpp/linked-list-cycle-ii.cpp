/* Problem url: https://leetcode.com/problems/linked-list-cycle-ii
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* node1 = head, * node2 = head;
        while (true) {
            if (node1->next == NULL || node2->next == NULL || node2->next->next == NULL) {
                break;
            }
            node1 = node1->next;
            node2 = node2->next->next;
            if (node1 == node2) {
                node1 = head;
                queue<ListNode*> q;
                while (node1->next) {
                    node2 = node1->next;
                    node1->next = NULL;
                    node1 = node2;
                    q.push(node1);
                }
                node2 = head;
                while (!q.empty()) {
                    node2->next = q.front();
                    node2 = node2->next;
                    q.pop();
                }
                return node1;
            }
        }
        return NULL;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: linked list, fun
 * 
 * */
