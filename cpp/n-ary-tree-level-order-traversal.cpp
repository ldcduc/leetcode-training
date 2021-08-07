/* Problem url: https://leetcode.com/problems/n-ary-tree-level-order-traversal
 * Code by: ldcduc
 * */
/* Begin of Solution */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void visit(Node* node, int level, vector<vector<int>> &result) {
        if (node) {
            if (result.size() == level) {
                result.push_back(vector<int> (1, node->val));
            } 
            else {
                result[level].push_back(node->val);
            }
            for (int i = 0; i < node->children.size(); ++ i) {
                visit(node->children[i], level + 1, result);
            }
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        visit(root, 0, result);
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: graph, traversal
 * 
 * */
