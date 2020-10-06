/* Problem url: https://leetcode.com/problems/range-sum-query-2d-immutable
 * Code by: ldcduc
 * */
/* Begin of Solution */
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        sum.resize(matrix.size());
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j) {
                int sum_ = matrix[i][j];
                sum_ += i > 0 ? sum[i - 1][j] : 0;
                sum_ += j > 0 ? sum[i][j - 1] : 0;
                sum_ -= i > 0 && j > 0 ? sum[i - 1][j - 1] : 0;
                sum[i].push_back(sum_);
            }
        }    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = sum[row2][col2];
        result -= row1 > 0 ? sum[row1 - 1][col2] : 0;
        result -= col1 > 0 ? sum[row2][col1 - 1] : 0;
        result += row1 > 0 && col1 > 0 ? sum[row1 - 1][col1 - 1] : 0;
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: accumulated sum
 * 
 * */
