/* Problem url: https://leetcode.com/problems/cherry-pickup-ii/
 * Code by: ldcduc
 * */
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int> > > f(rows);
        for (int i=0; i<rows; ++i) {
            f[i] = vector<vector<int> >(cols);
            for (int j=0; j<cols; ++j) {
                f[i][j] = vector<int>(cols);
                for (int k=0; k<cols; ++k) {
                    f[i][j][k] = -1e9;
                }
            }
        }
        int result = 0;
        f[0][0][cols-1] = grid[0][0] + grid[0][cols-1];
        for (int i=1; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                for (int k=j; k<cols; ++k) {
                    for (int c1=-1; c1<=1; ++c1) {
                        for (int c2=-1; c2<=1; ++c2) {
                            if (j + c1 > -1 && j + c1 < cols && k + c2 > -1 && k + c2 < cols) {
                                f[i][j][k] = max(f[i][j][k], f[i - 1][j + c1][k + c2]);
                            }
                        }
                    }
                    f[i][j][k] += grid[i][j] + grid[i][k] - grid[i][j] * (j == k);
                    if (i == rows-1 && f[i][j][k] > result) {
                        result = f[i][j][k];
                    }
                }
            }
        }
        return result;
    }
};


/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 *
 * */
