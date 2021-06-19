/* Problem url: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool isNoZero(int n) {
        int tmp = n, result = true;
        while (tmp) {
            result &= tmp % 10 != 0; 
            tmp /= 10;
        }
        return result;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for (int i = 1; i <= n / 2; ++ i) {
            if (isNoZero(i) && isNoZero(n - i)) {
                result.push_back(i);
                result.push_back(n - i);
                break;
            }
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
