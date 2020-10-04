/* Problem url: https://leetcode.com/problems/majority-element
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0], vote = 1;
        for (int i = 1; i < nums.size(); ++ i) {
            if (vote) {
                if (nums[i] == result) {
                    ++ vote;
                } else {
                    -- vote;
                }
            } else {
                vote = 1;
                result = nums[i];
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: Boyer–Moore majority vote algorithm
 * 
 * */
