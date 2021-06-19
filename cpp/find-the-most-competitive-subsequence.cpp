/* Problem url: https://leetcode.com/problems/find-the-most-competitive-subsequence
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int trials = nums.size() - k;        
        vector<int> stack_;
        for (int i = 0; i < nums.size(); ++ i) {
            while (!stack_.empty() && nums[i] < stack_.back() && trials) {
                stack_.pop_back();
                -- trials;
            }
            stack_.push_back(nums[i]);
        }
        for (int i = stack_.size(); i > k; -- i) {
            stack_.pop_back();
        }
        return stack_;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack, greedy; heap
 * 
 * */
