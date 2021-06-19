/* Problem url: https://leetcode.com/problems/sudoku-solver
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool complete = false;
    vector<bool> subBox[9], row[9], col[9];
    Solution() {
        for (int i = 0; i < 9; ++ i) {
            subBox[i].resize(9, 0);
            row[i].resize(9, 0);
            col[i].resize(9, 0);
        }
    }
    void Recursion(vector<vector<char>>& board, int x, int y) {
        if (x < 9 && !complete) {
            if (board[x][y] != '.') {
                Recursion(board, y == 8 ? x + 1 : x, (y + 1) % 9);
            } else {
                for (int i = 0; i < 9; ++ i) {
                    if (!complete && !subBox[(x / 3) * 3 + y / 3][i] && !row[x][i] && !col[y][i]) {
                        subBox[(x / 3) * 3 + y / 3][i] = true;
                        row[x][i] = true;
                        col[y][i] = true; 
                        board[x][y] = '0' + i + 1;
                        Recursion(board, y == 8 ? x + 1 : x, (y + 1) % 9);
                        if (!complete) {
                            board[x][y] = '.';
                            subBox[(x / 3) * 3 + y / 3][i] = false;
                            row[x][i] = false;
                            col[y][i] = false; 
                        }
                    }    
                }
            }
        } else {
            complete = true;
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++ i) {
            for (int j = 0; j < 9; ++ j) {
                if (board[i][j] != '.') {
                    subBox[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1] = true;
                    row[i][board[i][j] - '0' - 1] = true;
                    col[j][board[i][j] - '0' - 1] = true;
                }
            }
        }
        Recursion(board, 0, 0);    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
