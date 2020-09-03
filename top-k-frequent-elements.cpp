/* Problem url: https://leetcode.com/problems/top-k-frequent-elements
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int lastVal = nums[0], cnt = 0;
        priority_queue<pair<int, int> > s;
        for (auto num : nums) {
            if (lastVal == num) {
                ++cnt;
            } else {
                s.push(make_pair(cnt, lastVal));
                lastVal = num;
                cnt = 1;
            }
        }
        s.push(make_pair(cnt, lastVal));
        while (k) {
            result.push_back(s.top().second);
            s.pop();
            --k;
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags:
 * 
 * */

