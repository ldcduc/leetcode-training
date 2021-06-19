/* Problem url: https://leetcode.com/problems/ugly-number-iii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    long long lcm(int x, int y) {
        return 1ll * x / gcd(x, y) * y;
    }
    long long lcm(int x, int y, int z) {
        return lcm(lcm(x, y), z);
    }
    int calculate(long long val, int a, int b, int c) {
        return val / a + val / b + val / c - val / lcm(a, b) - val / lcm(a, c) - val / lcm(b, c) + val / lcm(a, b, c);
    } 
    int nthUglyNumber(int n, int a, int b, int c) {
        int l = 0, r = 2000000000, result;
        while (l <= r) {
            int m = (1ll*l + r) / 2;
            int tmp = calculate(m, a, b, c);
            if (tmp > n) {
                r = m - 1;    
            } else if (tmp < n) {
                l = m + 1; 
            } else {
                result = m;
                r = m - 1;
            }
        }
        return l;
    }
};

/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: math, binary search
 * 
 * */
