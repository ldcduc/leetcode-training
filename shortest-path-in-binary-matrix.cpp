/* Problem url: https://leetcode.com/problems/shortest-path-in-binary-matrix
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, m + n + 1));
        queue<pair<int, int>> Q;
        if (grid[0][0] == 0) {
            dp[0][0] = 1;
            Q.push(make_pair(0, 0));
        }
        while (!Q.empty()) {
            auto [r, c] = Q.front();
            Q.pop();
            for (int i = -1; i < 2; ++ i) {
                for (int j = -1; j < 2; ++ j) {
                    if (i || j ) {
                        int rr = r + i, cc = c + j;    
                        if (!(rr < 0 || cc < 0 || rr == m || cc == n)) {
                            if (!grid[rr][cc] && dp[rr][cc] == m + n + 1) {
                                dp[rr][cc] = dp[r][c] + 1;
                                Q.push(make_pair(rr, cc));
                            }
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1] == m + n + 1 ? -1 : dp[m - 1][n - 1];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: BFS
 * 
 * */
