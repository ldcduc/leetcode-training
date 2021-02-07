/* Problem url: https://leetcode.com/problems/swapping-nodes-in-a-linked-list
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
    vector<ListNode*> state;
    void recursion(ListNode* node, int k, int index, int &rindex) {
        if (node) {
            if (index == k) {
                state.push_back(node);
            }
            recursion(node->next, k, index + 1, rindex);
            ++ rindex;
            if (rindex == k) {
                state.push_back(node);
            }
        } else {
            rindex = 0;
        }
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int rindex;
        recursion(head, k, 1, rindex);
        swap(state[0]->val, state[1]->val);
        return head;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
