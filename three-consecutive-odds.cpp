/* Problem url: https://leetcode.com/problems/three-consecutive-odds
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (auto num : arr) {
            cnt = cnt * (num & 1) + (num & 1);
            if (cnt == 3) {
                return true;
            }
        }
        return false;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: fun, trick
 * 
 * */
