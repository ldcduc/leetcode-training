/* Problem url: https://leetcode.com/problems/arranging-coins/
 * Code by: ldcduc
 * */
class Solution {
public:
    int arrangeCoins(int n) {
        int k = sqrt((long long) 2*n);
        return ((long long) k*(k+1)/2 <= n) ? k : k - 1;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, careful
 * 
 * */
