/* Problem url: https://leetcode.com/problems/n-queens-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<bool> column, dia1, dia2;

    int recursion(int row, int n) {
        if (row < n) {
            int result = 0;
            for (int col = 0; col < n; ++ col) {
                if (column[col] + dia1[row + col] + dia2[row - col + n] == 0) {
                    column[col] = true;
                    dia1[row + col] = true;
                    dia2[row - col + n] = true;
                    result += recursion(row + 1, n);
                    column[col] = false;
                    dia1[row + col] = false;
                    dia2[row - col + n] = false;
                }
            }
            return result;
        }
        return 1;
    }
    int totalNQueens(int n) {
        column.resize(n, 0);
        dia1.resize(2 * n, 0); // row + col
        dia2.resize(2 * n, 0); // row - col + n
        return recursion(0, n);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
