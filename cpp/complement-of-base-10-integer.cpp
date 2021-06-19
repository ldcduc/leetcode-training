/* Problem url: https://leetcode.com/problems/complement-of-base-10-integer
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int bitwiseComplement(int N) {
        int oneMask = 0;    
        for (int tmpN = N; tmpN; tmpN >>= 1, oneMask = oneMask * 2 + 1);
        return N ? ~N & oneMask : 1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation
 * 
 * */
