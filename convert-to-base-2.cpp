/* Problem url: https://leetcode.com/problems/convert-to-base-2
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string baseNeg2(int N) {
        string result = N == 0 ? "0" : "";
        int pow = 1;
        while (N != 0) {
            int r = N % 2;
            r = r < 0 ? 2 + r : r;
            N = (N - r) / -2;
            result += (char) (r + '0');     
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
