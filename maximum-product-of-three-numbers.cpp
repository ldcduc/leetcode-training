/* Problem url: https://leetcode.com/problems/maximum-product-of-three-numbers
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void maximize(int &first, bool &optimized, int second) {
        if (!optimized || second > first) {
            first = second;
            optimized = true;
        }
    }
    int maximumProduct(vector<int>& nums) {
        int result; bool optimized = false;
        vector<int> positive;
        vector<int> negative;
        for (auto num : nums) {
            if (num >= 0) {
                positive.push_back(num);
            } else {
                negative.push_back(num);
            }
        }
        sort(negative.begin(), negative.end());
        sort(positive.rbegin(), positive.rend());
        if (positive.size() >= 3) {
            maximize(result, optimized, positive[0] * positive[1] * positive[2]);
        }
        if (negative.size() >= 2 && positive.size() >= 1) {
            maximize(result, optimized, negative[0] * negative[1] * positive[0]);
        }
        if (negative.size() >= 3) {
            maximize(result, optimized, negative[0] * negative[1] * negative[2]);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
