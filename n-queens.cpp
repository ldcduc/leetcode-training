/* Problem url: https://leetcode.com/problems/n-queens
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<bool> column, dia1, dia2;
    vector<int> chosen;
    vector<vector<string>> result;
    
    int recursion(int row, int n) {
        if (row < n) {
            int count = 0;
            for (int col = 0; col < n; ++ col) {
                if (column[col] + dia1[row + col] + dia2[row - col + n] == 0) {
                    column[col] = true;
                    dia1[row + col] = true;
                    dia2[row - col + n] = true;
                    chosen.push_back(col);
                    count += recursion(row + 1, n);
                    chosen.pop_back();
                    column[col] = false;
                    dia1[row + col] = false;
                    dia2[row - col + n] = false;
                }
            }    
            return count;
        }
        vector<string> placement;
        string pattern;
        for (int i = 0; i < n; ++ i) {
            pattern += '.';
        }
        for (int i = 0; i < n; ++ i) {
            pattern[chosen[i]] = 'Q';
            placement.push_back(pattern);
            pattern[chosen[i]] = '.';
        }
        result.push_back(placement);
        return 1;
    }
    vector<vector<string>> solveNQueens(int n) {
        column.resize(n, 0);        
        dia1.resize(2 * n, 0); // row + col
        dia2.resize(2 * n, 0); // row - col + n
        recursion(0, n);
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
