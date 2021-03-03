/* Problem url: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int side = 0, result = 0;
        for (int i = 0; i < rectangles.size(); ++ i) {
            if (min(rectangles[i][0], rectangles[i][1]) >= side) {
                result = min(rectangles[i][0], rectangles[i][1]) == side ? result + 1 : 1;
                side = min(rectangles[i][0], rectangles[i][1]);
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
