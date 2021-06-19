/* Problem url: https://leetcode.com/problems/xor-operation-in-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = 0; i < n; ++ i) {
            result ^= start + 2 * i;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, bit manipulation
 * 
 * */
