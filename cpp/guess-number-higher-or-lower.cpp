/* Problem url: https://leetcode.com/problems/guess-number-higher-or-lower
 * Code by: ldcduc
 * */
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l = 1, r = n;
        while (l <= r) {
            long long m = (l + r) >> 1;
            int t = guess(m);
            if (!t) {
                return m;
            } else if (t > 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 0;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

