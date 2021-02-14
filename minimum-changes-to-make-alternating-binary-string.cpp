/* Problem url: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minOperations(string s) {
        int res1 = 0, res2 = 0;
        for (int i = 0; i < s.length(); ++ i) {
            res1 += (s[i] - '0') != i % 2;
            res2 += (s[i] - '0') != (1 - i % 2);
        }
        return min(res1, res2);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
