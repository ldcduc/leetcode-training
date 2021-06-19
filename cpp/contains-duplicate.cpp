/* Problem url: https://leetcode.com/problems/contains-duplicate
 * Code by: ldcduc
 * */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (auto num : nums) {
            if (m.count(num)) {
                return true;
            }
            m[num] = true;
        }
        return false;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

