/* Problem url: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isPrime(int num) {
        for (int i = 2; i * i <= num; ++ i) {
            if (num % i == 0) {
                return false;
            }
        }
        return num > 1;
    }
    int countPrimeSetBits(int L, int R) {
        int result = 0;    
        for (int i = L; i <= R; ++ i) {
            result += isPrime(__builtin_popcount(i));
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
