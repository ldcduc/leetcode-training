/* Problem url: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> moduloClass(k, 0);
        for (int i = 0; i < arr.size(); ++ i) {
            ++ moduloClass[(abs(arr[i]) * 1ll * k + arr[i]) % k];
        }
        bool result = true;
        for (int i = 0; i < k; ++ i) {
            if (i == 0) {
                result &= moduloClass[i] % 2 == 0;
            } else {
                result &= moduloClass[i] == moduloClass[k - i];
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: math, counting
 * 
 * */
