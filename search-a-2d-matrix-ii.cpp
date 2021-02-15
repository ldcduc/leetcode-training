/* Problem url: https://leetcode.com/problems/search-a-2d-matrix-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = m - 1, col = 0;
        while (row >= 0 && col < n) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                ++ col;
            } else {
                -- row;
            }
        }
        return false;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
