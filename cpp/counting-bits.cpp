/* Problem url: https://leetcode.com/problems/counting-bits/
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<int> countBits(int num) { // Much shorter solution
        vector<int> result(num + 1, 0);
        for (int i=1; i<=num; ++i) {
            result[i] = 1 + result[i & (i - 1)];
        }
        return result;
    }

    /*
    vector<int> countBits(int num) { // Shorter solution
        vector<int> result(num + 1, 0);
        int k = -1;
        for (int i=1; i<=num; ++i) {
            if (1ll << (k + 1) == i) 
                ++k;
            result[i] = 1 + result[i - (1 << k)];
        }
        return result;
    }
    */
     
    /* vector<int> countBits(int num) { */
    /*     vector<int> result(num + 1, 0); */
    /*     for (int i=0; (1<<i)<=num; ++i) */
    /*         result[1<<i] = 1; */
    /*     for (int value=1; value<=num; ++value) */
    /*         result[value] = result[value - (value & -value)] + result[value & -value]; */
    /*     return result; */
    /* } */
};
/*
 * Comment by ldcduc
 * Suggested tags: dp, bitwise operation
 * 
 * */

