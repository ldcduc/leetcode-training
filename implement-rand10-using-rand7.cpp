/* Problem url: https://leetcode.com/problems/implement-rand10-using-rand7
 * Code by: ldcduc
 * */
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int d1, d2, x;
        do {
            d1 = rand7() % 7;
            d2 = rand7() % 7;
            x = 7 * d1 + d2;
        } while (x >= 40);

        return x % 10 + 1;
    }
};

/*
 * Comment by ldcduc
 * Suggested tags: random, reject sampling, math
 * 
 * */

