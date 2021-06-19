/* Problem url: https://leetcode.com/problems/prime-arrangements
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numPrimeArrangements(int n) {
        const int MOD = 1e9 + 7;
        int result = 1, prime = 0;
        for (int num = 2; num <= n; ++ num) {
            int ok = true;
            for (int i = 2; i * i <= num; ++ i) {
                ok &= num % i > 0;
            }
            if (ok) {
                ++ prime;
                result = 1ll * result * prime % MOD;
            }
        }    
        for (int i = 1; i <= n - prime; ++ i) {
            result = 1ll * result * i % MOD;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: implementation
 * 
 * */
