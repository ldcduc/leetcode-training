/* Problem url: https://leetcode.com/problems/fibonacci-number
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int fib(int N) {
        return N < 2 ? N : fib(N - 1) + fib(N - 2);      
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
