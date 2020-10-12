/* Problem url: https://leetcode.com/problems/next-greater-element-iii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int tmpN = n;
        while (tmpN) {
            digits.push_back(tmpN % 10);
            tmpN /= 10;
        }
        if (next_permutation(digits.rbegin(), digits.rend())) {
            long long result = 0;
            for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++ it) {
                result = result * 10 + *it;    
            }    
            return (int) result > n ? result : -1;
        }
        return -1;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: permutation
 * 
 * */
