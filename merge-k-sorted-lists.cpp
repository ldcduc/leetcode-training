/* Problem url: https://leetcode.com/problems/merge-k-sorted-lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL, * node = NULL;
        int k = lists.size();    
        priority_queue<pair<int, int>> Q;
        for (int i = 0; i < k; ++ i) {
            if (lists[i]) {
                Q.push(make_pair(-lists[i]->val, i));
            }
        }
        while (!Q.empty()) {
            int i = Q.top().second;
            Q.pop();
            if (node == NULL) {
                node = new ListNode(lists[i]->val);    
                result = node;
            } else {
                node->next = new ListNode(lists[i]->val); 
                node = node->next;
            }
            lists[i] = lists[i]->next;
            if (lists[i]) {
                Q.push(make_pair(-lists[i]->val, i));
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
