/* Problem url: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastPos = -k - 1;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i]) {
                if (i - lastPos < k + 1) {
                    return false;
                }
                lastPos = i;
            }
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
