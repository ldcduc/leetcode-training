/* Problem url: https://leetcode.com/problems/valid-perfect-square
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int mySqrt(int x) {
        int result;
        double l = 0, r = x;
        for (int i = 0; i < 100; ++ i) {
            double m = (l + r) / 2;
            if (m * m > x && m * m - x < 1e-3) {
                result = floor(m);
                return result;
                break;
            } else if (m * m < x) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;    
    }
    bool isPerfectSquare(int num) {
        return mySqrt(num) * mySqrt(num) == num;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
