/* Problem url: https://leetcode.com/problems/magic-squares-in-grid
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y) {
        int tmp =  grid[x - 1][y - 1] + grid[x][y] + grid[x + 1][y + 1];
        if (grid[x + 1][y - 1] + grid[x][y] + grid[x - 1][y + 1] != 15 || tmp != 15) {
            return false;
        }
        for (int i = -1; i <= 1; ++ i) {
            if (grid[x - 1][y + i] + grid[x][y + i] + grid[x + 1][y + i] != tmp ||
                grid[x + i][y - 1] + grid[x + i][y] + grid[x + i][y + 1] != tmp) {
                return false;
            }
        }
        vector<int> arr;
        for (int i = -1; i <= 1; ++ i) {
            for (int j = -1; j <= 1; ++ j) {
                if (grid[x + i][y + j] < 1 || grid[x + i][y + j] > 9) {
                    return false;
                }
                arr.push_back(grid[x + i][y + j]);
            }
        }
        for (int i = 1; i < 9; ++ i) {
            if (arr[i] == arr[i - 1]) {
                return false;
            }
        }
        */
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), result = 0;
        if (row > 2 && col > 2) {
            for (int xcenter = 1; xcenter < row - 1; ++ xcenter) {
                for (int ycenter = 1; ycenter < col - 1; ++ ycenter) {
                    result += check(grid, xcenter, ycenter);
                }
            }    
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
