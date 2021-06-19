/* Problem url: https://leetcode.com/problems/copy-list-with-random-pointer
 * Code by: ldcduc
 * */
/* Begin of Solution */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head_new = NULL, * cur_new;
        if (head) {
            Node* cur = head;
            unordered_map<Node*, Node*> M;
            while (cur) {
                if (cur == head) {
                    head_new = new Node(cur->val);
                    cur_new = head_new;
                } else {
                    cur_new->next = new Node(cur->val);
                    cur_new = cur_new->next;
                }
                cur_new->random = cur->random;
                M[cur] = cur_new;
                cur = cur->next;
            }
            cur_new = head_new;
            while (cur_new) {
                cur_new->random = M[cur_new->random];
                cur_new = cur_new->next;
            }
        }
        return head_new;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: linked list
 * 
 * */
