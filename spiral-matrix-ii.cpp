/* Problem url: https://leetcode.com/problems/spiral-matrix-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int dir = 0, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int x = 0, y = -1; 
        for (int i = 1; i <= n * n; ++ i) {
            while (!(x + dx[dir] >= 0 && x + dx[dir] < n && y + dy[dir] >= 0 && y + dy[dir] < n && !result[x + dx[dir]][y + dy[dir]])) {
                dir = (dir + 1) % 4;
            }        
            x = x + dx[dir];
            y = y + dy[dir];
            result[x][y] = i;
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
