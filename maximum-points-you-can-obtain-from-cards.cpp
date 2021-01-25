/* Problem url: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        priority_queue<pair<int, int>> Q;         
        vector<int> prefixSum(cardPoints.size() + 1, 0);
        for (int i = 1; i <= cardPoints.size(); ++ i) {
            prefixSum[i] = prefixSum[i - 1] + cardPoints[i - 1];
        }
        int sum = 0, result = prefixSum[k], n = cardPoints.size();
        for (int i = cardPoints.size() - 1; i >= 0; -- i) {
            sum += cardPoints[i];
            if (k - n + i >= 0) {
                if (sum + prefixSum[k - n + i] > result) {
                    result = sum + prefixSum[k - n + i];    
                }
            } else {
                break;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array, dynamic programming
 * 
 * */
