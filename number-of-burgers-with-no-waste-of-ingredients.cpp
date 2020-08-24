/* Problem url: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> result;
        if (tomatoSlices % 2) {
            return result;
        }
        int small, jumbo = tomatoSlices / 2 - cheeseSlices;
        small = cheeseSlices - jumbo;
        if (small < 0 || jumbo < 0) {
            return result;
        }
        result.push_back(jumbo);
        result.push_back(small);
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math
 * 
 * */
