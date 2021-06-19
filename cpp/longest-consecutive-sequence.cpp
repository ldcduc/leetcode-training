/* Problem url: https://leetcode.com/problems/longest-consecutive-sequence
 * Code by: ldcduc
 * */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = nums.size() > 0;
        unordered_map<int, int> umap;
        for (auto value : nums) {
            umap[value] = 1;
        }
        for (auto value : nums) {
            if (umap.find(value - 1) != umap.end()) {
                continue;
            } else if (umap.find(value + 1) != umap.end()) {
                int res = 2;
                for (int i=2; ; ++i) {
                    if (umap.find(value + i) == umap.end()) {
                        break;
                    } else {
                        ++res;
                    }
                }
                result = max(result, res);
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: linear complexity
 * Be careful with the corner cases
 * */

