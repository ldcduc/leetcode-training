/* Problem url: https://leetcode.com/problems/sort-the-matrix-diagonally
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                arr.push_back(make_pair(i - j, mat[i][j]));
            }
        }
        sort(arr.begin(), arr.end());
        int size = arr.size();
        arr.push_back(make_pair(m + n, -1)); // pivot element
        
        vector<vector<int>> result(m, vector<int> (n));
        int row = 0, col = n - 1;
        for (int i = 0; i < size; ++ i) {
            int j;
            for (j = 0; arr[i + j].first == arr[i].first; ++ j) {
                result[row + j][col + j] = arr[i + j].second;    
            }    
            i += j - 1;
            row += (col == 0);
            col -= (col > 0);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: matrix, trick, fun
 * 
 * */
