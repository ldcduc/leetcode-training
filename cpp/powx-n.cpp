/* Problem url: https://leetcode.com/problems/powx-n
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    unordered_map<int, double> mem;
    Solution() {
        mem[0] = 1;
    }
    double myPow(double x, int n) {
        if (mem.count(n) == 0) {
            mem[n] = myPow(x, n / 2) * myPow(x, n / 2) * (n % 2 ? (n < 0 ? 1.0/x : x) : 1);
        }
        return mem[n];
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
