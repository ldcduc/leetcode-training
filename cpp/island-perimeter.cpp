/* Problem url: https://leetcode.com/problems/island-perimeter
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int Dx[4] = {-1, 0, 1, 0}, Dy[4] = {0, 1, 0, -1};    
        int result = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (grid[i][j]) {
                    for (int dir = 0; dir < 4; ++ dir) {
                        int x = i + Dx[dir], y = j + Dy[dir];
                        result += (x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] == 0);
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
 * Suggested tags: adhoc
 * 
 * */
