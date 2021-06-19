/* Problem url: https://leetcode.com/problems/increasing-triplet-subsequence
 * Code by: ldcduc
 * */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long firstMin = 1ll << 31, secondMin = 1ll << 32;         
        for (auto num : nums) {
            if (num > secondMin && secondMin > firstMin) {
                cout << num << ' ' << secondMin << ' ' << firstMin << endl;
                return true;
            }
            if (num < firstMin) {
                firstMin = num;
            } else if (num > firstMin && num < secondMin) {
                secondMin = num;
            }
        } 
        return false;
    }
};

/*
 * Comment by ldcduc
 * Suggested tags: fun
 * 
 * */
