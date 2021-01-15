/* Problem url: https://leetcode.com/problems/plus-one
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result(digits.size(), 0);
        int remainder = 1;
        for (int i = digits.size() - 1; i >= 0; -- i) {
            remainder += digits[i];
            result[i] = remainder % 10;
            remainder /= 10;
        }
        if (remainder > 0) {
            result.push_back(0);
            for (int i = result.size() - 1; i > 0; -- i) {
                result[i] = result[i - 1];
            }
            result[0] = remainder;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: implementation, array
 * 
 * */
