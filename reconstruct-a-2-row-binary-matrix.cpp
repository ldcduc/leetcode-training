/* Problem url: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size(), noSolution = false;
        vector<vector<int>> result(2, vector<int> (n, 0));    
        for (int i = 0; i < n; ++ i) {
            if (colsum[i] == 2) {
                result[0][i] = result[1][i] = 1;
                if (upper == 0 || lower == 0) {
                    noSolution = true;
                    break;
                }
                -- upper;
                -- lower;
                colsum[i] = 0;
            }
        }
        for (int i = 0; i < n; ++ i) {
            if (colsum[i] == 1) {
                if (upper > 0) {
                    result[0][i] = 1;                                
                    -- upper;
                } else if (lower > 0) {
                    result[1][i] = 1; 
                    -- lower;
                } else {
                    noSolution = true;
                    break;
                }
            }
        }
        if (upper > 0 || lower > 0 || noSolution) {
            result.clear();
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, implementation
 * 
 * */
