/* Problem url: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> result(m, vector<int> (n));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Qrow;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Qcol;
        for (int i = 0; i < rowSum.size(); ++ i) {
            Qrow.push(make_pair(rowSum[i], i));
        }
        for (int i = 0; i < colSum.size(); ++ i) {
            Qcol.push(make_pair(colSum[i], i));
        }
        for (int i = 0; i < m * n; ++ i) {
            int rowVal = Qrow.top().first, rowId = Qrow.top().second;
            int colVal = Qcol.top().first, colId = Qcol.top().second;
            Qrow.pop();
            Qcol.pop();
            int val = min(rowVal, colVal);
            result[rowId][colId] = val;
            rowVal -= val;
            colVal -= val;
            if (rowVal) {
                Qrow.push({rowVal, rowId});
            }
            if (colVal) {
                Qcol.push({colVal, colId});
            }
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
