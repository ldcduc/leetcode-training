/* Problem url: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++ i) {
            int l = 0, r = grid[i].size() - 1, res = grid[i].size();
            while (l <= r) {
                int m = (l + r) / 2;
                if (grid[i][m] < 0) {
                    res = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } 
            result += grid[i].size() - res;
        }        
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
