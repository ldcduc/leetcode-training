/* Problem url: https://leetcode.com/problems/swap-nodes-in-pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head) {
            if (head->next) {
                ListNode* second = head->next;
                head->next = swapPairs(second->next);
                second->next = head;
                return second;
            }
            return head;
        }
        return head;
    }
};

class NonRecursionSolution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* firstNode = head;
        ListNode* secondNode = NULL; 
        ListNode* result = head && head->next ? head->next : head;
        while (firstNode) {
            if (firstNode->next) { 
                if (secondNode) {
                    secondNode->next = firstNode->next;
                } 
                // A -> B -> C
                // firstNode = A
                secondNode = firstNode->next; // secondnode = B
                
                // goal: B -> A -> C
                firstNode->next = secondNode->next; 
                secondNode->next = firstNode;
                // achieved: B -> A -> C
                secondNode = firstNode; // secondNode will serve as previous node
                firstNode = firstNode->next;
            } else {
                firstNode = NULL;
            }
        }    
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion, linked list
 * 
 * */
