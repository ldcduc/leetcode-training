/* Problem url: https://leetcode.com/problems/the-kth-factor-of-n
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1, cnt = 0; i <= n; ++ i) {
            cnt += !(n % i);
            if (cnt == k) {
                return i;
            }
        }
        return -1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
