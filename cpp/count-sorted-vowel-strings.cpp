/* Problem url: https://leetcode.com/problems/count-sorted-vowel-strings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class RecursiveSolution {
public:
    int recursion(int n, int last) {
        int result = 0;
        if (n == 0) {
            return 1;
        } else {
            for (int i = last; i < 5; ++ i) {
                result += recursion(n - 1, i);
            }
        }
        return result;
    }
    int countVowelStrings(int n) {
        return recursion(n, 0); 
    }
};
class DPSolution {
public:
    int countVowelStrings(int n) {
        int result = n == 1 ? 5 : 0;
        vector<vector<int>> dp(n, vector<int>(5));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 1;
        for (int i = 1; i < n; ++ i) {
            for (int j = 0; j < 5; ++ j) {
                dp[i][j] = 0;
                for (int t = 0; t <= j; ++ t) {
                    dp[i][j] += dp[i - 1][t];
                }
                result += (i == n - 1) * dp[i][j];
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion, dynamic programming
 * 
 * */
