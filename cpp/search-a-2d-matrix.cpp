/* Problem url: https://leetcode.com/problems/search-a-2d-matrix
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();    
        int lx = 0, rx = m - 1, ly = 0, ry = n - 1;
        while (lx <= rx && ly <= ry) {
            int mx = (lx + rx) >> 1;
            int my = (ly + ry) >> 1;
            if (matrix[mx][my] == target) {
                return true;
            }
            if (matrix[mx][n - 1] < target) {
                lx = mx + 1;    
            } else if (target < matrix[mx][0]) {
                rx = mx - 1; 
            } else {
                lx = rx = mx;
                if (matrix[mx][my] < target) {
                    ly = my + 1;
                } else {
                    ry = my - 1;
                }
            }
        }
        return false;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
