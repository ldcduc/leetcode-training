/* Problem url: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int V = 0; // number of vertices
        for (auto edge : edges) {
            V = max(V, max(edge[0], edge[1]));
        }
        vector<vector<int>> matrix(V, vector<int> (V, 0));
        vector<int> deg(V, 0); 
        for (auto edge : edges) {
            ++ deg[edge[0] - 1];
            ++ deg[edge[1] - 1];
            matrix[edge[0] - 1][edge[1] - 1] = true;
            matrix[edge[1] - 1][edge[0] - 1] = true;
        }
        int result = -1;
        for (int x = 0; x < V; ++ x) {
            for (int y = x + 1; y < V; ++ y) {
                for (int z = y + 1; z < V; ++ z) {
                    if (matrix[x][y] && matrix[y][z] && matrix[z][x]) {
                        if (result == -1) {
                            result = deg[x] + deg[y] + deg[z] - 6;
                        } else {
                            result = min(result, deg[x] + deg[y] + deg[z] - 6);        
                        }
                    }
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
