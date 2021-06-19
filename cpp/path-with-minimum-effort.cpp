/* Problem url: https://leetcode.com/problems/path-with-minimum-effort
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        int m = heights.size(), n = heights[0].size();    
        vector<int> visited(m * n, 0);
        vector<int> efforts(m * n, 1000000 + 1);
        efforts[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.push(make_pair(0, 0));
        while (!Q.empty()) {
            int x = Q.top().second / n;
            int y = Q.top().second % n;
            int effort = Q.top().first;
            if (x == m - 1 && y == n - 1) {
                return Q.top().first;
            }
            Q.pop();
            for (int dir = 0; dir < 4; ++ dir) {
                int newX = x + dx[dir], newY = y + dy[dir];
                if (0 <= newX && newX < m && 0 <= newY && newY < n && !visited[newX * n + newY]) {
                    int current_effort = max(effort, abs(heights[x][y] - heights[newX][newY]));
                    if (current_effort < efforts[newX* n + newY]) {
                        efforts[newX* n + newY] = current_effort;
                        Q.push(make_pair(current_effort, newX * n + newY));
                    }
                }
            }    
        }
        return 0;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
