/* Problem url: https://leetcode.com/problems/edit-distance
 * Code by: ldcduc
 * */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        int** dp = new int* [len1 + 1];
        for (int i=0; i<=len1; ++i) {
            dp[i] = new int [len2 + 1];
        }

        dp[0][0] = 0;
        for (int i=1; i<=len1; ++i) {
            dp[i][0] = i;
        }
        for (int j=1; j<=len2; ++j) {
            dp[0][j] = j;
        }
        for (int i=1; i<=len1; ++i) {
            for (int j=1; j<=len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }

        int result = dp[len1][len2];
        for (int i=0; i<=len1; ++i) {
            delete [] dp[i];
        }
        delete [] dp;
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: dynamic programming
 * 
 * */
