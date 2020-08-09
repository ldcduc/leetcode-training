/* Problem url: https://leetcode.com/problems/maximal-square/
 * Code by: ldcduc
 * */
class Solution {
public:
    int result = 0;
    void updateResult(int val1, int val2) {
        int chosen = min(val1, val2);
        this->result = max(this->result, chosen * chosen);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int width = (height == 0) ? width = 0 : matrix[0].size();
        vector<int> ones(width+1, 0);
        ones[width] = -1;

        for (int i=0; i<height; ++i) {
            stack<int> s;
            vector<int> left_(width + 1);
            for (int j=0; j<width; ++j) {
                ones[j] = (i == 0) ? (matrix[i][j] - '0') : (ones[j] + 1) * (matrix[i][j] - '0');
            }
            for (int j=0; j<=width; ++j) {
                left_[j] = j;
                while (!s.empty() && ones[s.top()] > ones[j]) {
                    updateResult(j - left_[s.top()], ones[s.top()]);
                    left_[j] = left_[s.top()];
                    s.pop();
                }
                s.push(j);
            }
        }

        return this->result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: stack applied, dynamic programming
 * 
 * */
