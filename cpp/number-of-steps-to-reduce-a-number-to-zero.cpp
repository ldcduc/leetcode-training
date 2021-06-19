/* Problem url: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numberOfSteps (int num) {
        int result = 0;
        for (int i = 0; i < 30; ++ i) {
            if (num >> i & 1) {
                result = i;
            }
        } 
        result += __builtin_popcount(num);
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation, implementation
 * 
 * */
