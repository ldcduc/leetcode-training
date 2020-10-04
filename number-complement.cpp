/* Problem url: https://leetcode.com/problems/number-complement
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findComplement(int num) {
        int oneMask = 0;    
        for (int tmpN = num; tmpN; tmpN >>= 1, oneMask = oneMask * 2 + 1);
        return num ? ~num & oneMask : 1;    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation
 * 
 * */
