/* Problem url: https://leetcode.com/problems/matrix-block-sum
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> answer(m, vector<int>(n, 0));
        vector<vector<int>> sum(m, vector<int>(n, 0));
        /* A B 
           C D */
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int A = (i > 0 && j > 0) ? sum[i - 1][j - 1] : 0;                       
                int B = (i > 0) ? sum[i - 1][j] : 0;
                int C = (j > 0) ? sum[i][j - 1] : 0;
                int D = mat[i][j];
                sum[i][j] = B + C + D - A;
            }
        }
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int upLeftRow = max(0, i - K), upLeftCol = max(0, j - K);
                int downRightRow = min(m - 1, i + K), downRightCol = min(n - 1, j + K);
                int A = (upLeftRow > 0 && upLeftCol > 0) ? sum[upLeftRow - 1][upLeftCol - 1] : 0;
                int B = (upLeftRow > 0) ? sum[upLeftRow - 1][downRightCol] : 0;
                int C = (upLeftCol > 0) ? sum[downRightRow][upLeftCol - 1] : 0;
                int D = sum[downRightRow][downRightCol];
                answer[i][j] = D - C - B + A;
            }
        }
        return answer;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: matrix, accumulated sum
 * 
 * */
