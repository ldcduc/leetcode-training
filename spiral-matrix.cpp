/* Problem url: https://leetcode.com/problems/spiral-matrix
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false))    ;
        vector<int> result;
        int dir = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = -1;
        for (int i = 1; i <= m * n; ++ i) {
            while (!(x + dx[dir] >= 0 && x + dx[dir] < m && y + dy[dir] >= 0 && y + dy[dir] < n && !visited[x + dx[dir]][y + dy[dir]])) {
                dir = (dir + 1) % 4;
            }
            x += dx[dir];
            y += dy[dir];
            result.push_back(matrix[x][y]);
            visited[x][y] = true;
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
