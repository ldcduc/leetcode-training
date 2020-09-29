/* Problem url: https://leetcode.com/problems/populating-next-right-pointers-in-each-node
 * Code by: ldcduc
 * */
/* Begin of Solution */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class RecursiveSolution {
public:
    void visit(Node* node) {
        if (node->left) {
            node->left->next = node->right;
            node->right->next = node->next ? node->next->left : NULL;
            visit(node->left);
            visit(node->right);
        }
    }
    Node* connect(Node* root) {
        if (root) {
            root->next = NULL;    
            visit(root);
        }        
        return root;
    }
};
class IterativeSolution {
public:
    Node* connect(Node* root) {
        if (root) {
            root->next = NULL;
            stack<Node*> S;
            S.push(root);
            while (!S.empty()) {
                Node* node = S.top();
                S.pop();
                if (node->left) {
                    node->left->next = node->right;
                    node->right->next = node->next ? node->next->left : NULL;
                    S.push(node->right);
                    S.push(node->left);
                }
            }
        }
        return root;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary tree, recursion
 * 
 * */
