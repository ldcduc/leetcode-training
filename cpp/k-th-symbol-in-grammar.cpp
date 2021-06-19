/* Problem url: https://leetcode.com/problems/k-th-symbol-in-grammar
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int kthGrammar(int N, int K) {
        return N == 1 ? 0 : kthGrammar(N - 1, (K + 1) / 2) == (K % 2);
    }
};

/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion, trick
 * 
 * */
