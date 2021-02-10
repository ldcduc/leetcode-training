/* Problem url: https://leetcode.com/problems/clone-graph
 * Code by: ldcduc
 * */
/* Begin of Solution */
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* result = NULL;
        if (node) {
            unordered_map<Node*, Node* > M;
            queue<Node*> Q;
            result = new Node(node->val);
            M[node] = result;
            Q.push(node);
            while (!Q.empty()) {
                node = Q.front();
                Q.pop();
                for (int i = 0; i < node->neighbors.size(); ++ i) {
                    Node* adj = node->neighbors[i];
                    if (M.count(adj) == 0) {
                        M[adj] = new Node(adj->val);
                        Q.push(adj);
                    }
                    M[node]->neighbors.push_back(M[adj]);
                }
            } 
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: graph
 * 
 * */
