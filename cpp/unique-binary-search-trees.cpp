/* Problem url: https://leetcode.com/problems/unique-binary-search-trees
 * Code by: ldcduc
 * */
/* Begin of Solution */
class RecursiveSolution {
public:
    unordered_map<int, int> M; 
    int recursion(int l, int r) {
        if (M.count(l * 100 + r) == 0) {
            if (l <= r) {
                int res = 0;
                for (int i = l; i <= r; ++ i) {
                    res += recursion(l, i - 1) * recursion(i + 1, r);
                }
                return M[l * 100 + r] = res;
            }
            return M[l * 100 + r] = 1;
        }
        return M[l * 100 + r];
    }
    
    int numTrees(int n) {
        return recursion(1, n);    
    }
};
class DynamicProgrammingSolution {
public:
    int numTrees(int n) {
        int * dp = new int [n+1];
        dp[0] = dp[1] = 1;
        for (int i=2; i<=n; ++i) {
            dp[i] = 0;
            for (int j=1; j<=i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        int result = dp[n];
        delete [] dp;
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion, memoization, dynamic programming
 * 
 * */
