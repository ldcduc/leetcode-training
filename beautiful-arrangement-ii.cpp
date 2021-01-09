/* Problem url: https://leetcode.com/problems/beautiful-arrangement-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result(1, 1);
        int L = 2, R = n;
        for (int i = 1; i < k; ++ i) {
            if (i % 2) {
                result.push_back(R --);
            } else {
                result.push_back(L ++);
            }
        }
        k = n - k;
        bool flagr = result.back() == R + 1;
        for (int i = 0; i < k; ++ i) {
            result.push_back(flagr * (R --) + !flagr * (L ++));
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
