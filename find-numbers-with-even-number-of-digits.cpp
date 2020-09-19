/* Problem url: https://leetcode.com/problems/find-numbers-with-even-number-of-digits
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for (auto num : nums) {
            int tmp = num, cnt = 0;
            for (; tmp; tmp /= 10, ++cnt);
            result += (cnt % 2 == 0);
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
