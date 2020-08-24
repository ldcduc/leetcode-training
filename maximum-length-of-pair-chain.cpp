/* Problem url: https://leetcode.com/problems/maximum-length-of-pair-chain
 * Code by: ldcduc
 * */
bool compare(vector<int>& first, vector<int>& second) {
    if (first[0] == second[0]) {
        return first[1] < second[1];
    }
    return first[0] < second[0]; 
}

class Solution {
public:
    int* dp;
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int result = 0;
        int n = pairs.size();    
        dp = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++ i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++ j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1); 
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
    ~Solution() {
        free(dp);
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
