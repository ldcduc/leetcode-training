/* Problem url: https://leetcode.com/problems/pascals-triangle
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<int>> result;
    vector<int> getRow(int rowIndex) {
        if (rowIndex) {
            vector<int> tmp = getRow(rowIndex - 1);
            for (int i = 1, prev = 1; i < tmp.size(); ++ i) {
                prev += tmp[i];
                swap(prev, tmp[i]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
            return tmp;
        } else {
            result.push_back(vector<int> {1});
            return result[0];
        } 
    }
    vector<vector<int>> generate(int numRows) {
        if (numRows) {
            getRow(numRows - 1);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursive (easier than iterative)
 * 
 * */
