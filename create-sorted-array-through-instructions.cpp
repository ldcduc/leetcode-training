/* Problem url: https://leetcode.com/problems/create-sorted-array-through-instructions
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> T;
    const int modulo = 1e9 + 7;
    Solution() {
        T.resize(100001, 0);
    }
    void update(int label) {
        for (int i = label; i <= 100000; i += i & -i) {
            ++ T[i];
        }
    }
    int count(int label) {
        int res = 0;
        for (int i = label; i > 0; i -= i & -i) {
            res += T[i];
        }
        return res;
    }
    int createSortedArray(vector<int>& instructions) {
        int result = 0;
        for (int i = 0; i < instructions.size(); ++ i) {
            int t = min(count(instructions[i] - 1), i - count(instructions[i]));
            result = (result + t) % modulo;
            update(instructions[i]);
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
