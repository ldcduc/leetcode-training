/* Problem url: https://leetcode.com/problems/count-good-meals
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int mod = 1e9 + 7;
        vector<int> pow2;
        for (int i = 0; i <= 21; ++ i) {
            pow2.push_back(1 << i);
        }
        unordered_map<int, int> M; 
        int result = 0; 
        for (int i = 0; i < deliciousness.size(); ++ i) {
            for (int j = 0; j <= 21; ++ j) {
                if (M.count(pow2[j] - deliciousness[i]) > 0) {
                      result = (result + M[pow2[j] - deliciousness[i]]) % mod;
                }
            } 
            ++ M[deliciousness[i]];
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
