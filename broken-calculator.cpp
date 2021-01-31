/* Problem url: https://leetcode.com/problems/broken-calculator
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int result = 0;
        // Reverse transform Y to X
        while (Y > X) {
            if (Y % 2) {
                ++ Y;
            } else {
                Y >>= 1;
            }    
            ++ result;
        }
        result += X - Y;
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: fun
 * 
 * */
