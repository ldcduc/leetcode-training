/* Problem url: https://leetcode.com/problems/hamming-distance
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        for (int i = 0; i < 32; ++ i) {
            result += ((x >> i) & 1) ^ ((y >> i) & 1);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation
 * 
 * */
