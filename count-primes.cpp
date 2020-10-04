/* Problem url: https://leetcode.com/problems/count-primes
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int countPrimes(int n) {
        int result = 0;
        if (n > 2) {
            vector<bool> eliminated(n + 1, false);    
            for (int i = 2; i < n; ++ i) {
                if (!eliminated[i]) {
                    ++ result;
                    for (int j = i + i; j <= n; j += i) {
                        eliminated[j] = true;
                    }
                }    
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
