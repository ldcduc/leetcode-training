/* Problem url: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        for (int i = numbers.size() - 1; i >= 0; -- i) {
            int l = 0, r = i - 1, m;
            while (l <= r) {
                m = (l + r) >> 1;
                if (numbers[m] == target - numbers[i]) {
                    result.push_back(m + 1);
                    result.push_back(i + 1);
                    break;
                } else if (numbers[m] < target - numbers[i]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
