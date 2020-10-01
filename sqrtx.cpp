/* Problem url: https://leetcode.com/problems/sqrtx
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x;
        while (low <= high) {
            long long mid = (1ll * low + high) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low - 1;
    }
};

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
}
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
