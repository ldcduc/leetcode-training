/* Problem url: https://leetcode.com/problems/check-if-it-is-a-straight-line
 * Code by: ldcduc
 * */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }
        for (int i = 2; i < coordinates.size(); ++ i) {
            int x1, x2, y1, y2;
            x1 = coordinates[i - 1][0] - coordinates[i - 2][0];
            x2 = coordinates[i][0] - coordinates[i - 1][0];
            y1 = coordinates[i - 1][1] - coordinates[i - 2][1];
            y2 = coordinates[i][1] - coordinates[i - 1][1];
            if (1ll * x2 * y1 - 1ll * x1 * y2) {
                return false;
            }
        }
        return true;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, check clockwise, geometry
 * 
 * */

