/* Problem url: https://leetcode.com/problems/pascals-triangle-ii
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<long long> nums;
        vector<int> result;
        nums.push_back(1);
        result.push_back(1);
        if (!rowIndex) {
            return result;
        }
        nums.push_back(1);
        result.push_back(1);
        if (rowIndex == 1) {
            return result;
        }
        result.pop_back();

        for (int i = 2; i <= rowIndex; ++ i) {
            long long t = 1;
            for (int j = 1; j < i; ++ j) {
                nums[j] += t;
                t = nums[j] - t;
            }
            nums.push_back(1);
        }
        for (int i = 1; i < nums.size(); ++ i) {
            result.push_back(nums[i]);
        }
        return result;
    }
};

/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */

