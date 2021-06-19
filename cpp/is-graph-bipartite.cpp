/* Problem url: https://leetcode.com/problems/is-graph-bipartite
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> label(n, 0); 
        queue<int> Q;
        for (int start = 0; start < n; ++ start) {
            if (label[start] == 0) {
                label[start] = 1;
                Q.push(start);
                while (!Q.empty()) {
                    int node = Q.front();
                    Q.pop();
                    for (int i = 0; i < graph[node].size(); ++ i) {
                        int adj_node = graph[node][i];
                        if (label[adj_node] != 0) {
                            if (label[adj_node] == label[node]) {
                                return false;
                            } 
                        } else {
                            label[adj_node] = -label[node];
                            Q.push(adj_node);
                        }
                    }
                }
            }
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bfs, dfs, graph
 * 
 * */
