/* Problem url: https://leetcode.com/problems/rotate-image
 * Code by: ldcduc
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n) { 
            for (int i = 0; i < (n+1)/2; ++ i) {
                for (int j = 0; j < (n)/2; ++ j) {
                    int tmp = matrix[n - j - 1][i];
                    matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                    matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                    matrix[j][n - i - 1] = matrix[i][j];
                    matrix[i][j] = tmp; 
                }
            }
        }
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: matrix, fun
 * 
 * */
