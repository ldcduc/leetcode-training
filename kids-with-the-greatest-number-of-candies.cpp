/* Problem url: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxVal = candies[0];
        for (int i = 1; i < candies.size(); ++ i) {
            maxVal = max(maxVal, candies[i]);
        }
        for (int i = 0; i < candies.size(); ++ i) {
            result.push_back(candies[i] + extraCandies >= maxVal);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
