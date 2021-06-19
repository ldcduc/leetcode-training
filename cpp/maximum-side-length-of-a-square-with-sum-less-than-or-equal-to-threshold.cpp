/* Problem url: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int sumSquare(int x, int y, int len, vector<vector<int>>& sum) {
        int result = sum[x + len - 1][y + len - 1];
        result -= x > 0 ? sum[x - 1][y + len - 1] : 0;
        result -= y > 0 ? sum[x + len - 1][y - 1] : 0;
        result += x > 0 && y > 0 ? sum[x - 1][y - 1] : 0;
        return result;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> sum(mat);    
        for (int i = 0; i < mat.size(); ++ i) {
            for (int j = 0; j < mat[0].size(); ++ j) {
                sum[i][j] += i > 0 ? sum[i - 1][j] : 0;
                sum[i][j] += j > 0 ? sum[i][j - 1] : 0;
                sum[i][j] -= i > 0 && j > 0 ? sum[i - 1][j - 1] : 0;
            }
        }
        int l = 1, r = min(mat.size(), mat[0].size()), result = 0;
        while (l <= r) {
            int len = (l + r) / 2, ok = false;
            for (int i = 0; i < mat.size() - len + 1 && ok == false; ++ i) {
                for (int j = 0; j < mat[0].size() - len + 1; ++ j) {
                    if (sumSquare(i, j, len, sum) <= threshold) {
                        ok = true;
                        break;
                    }
                }
            } 
            if (ok) {
                result = len;
                l = len + 1;
            } else {
                r = len - 1;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
