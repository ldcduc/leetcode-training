/* Problem url: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n) {
            product *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return product - sum;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, implementation
 * 
 * */
