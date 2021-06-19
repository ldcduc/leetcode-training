/* Problem url: https://leetcode.com/problems/count-number-of-teams
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void updateTree(vector<int>& T, int index, int val) {
        while (index <= 100000) {
            T[index] += val;
            index += index & -index;
        }
    }
    int countTree(vector<int>& T, int index) {
        int result = 0;
        while (index) {
            result += T[index];
            index -= index & -index;
        }
        return result;
    }
    int numTeams(vector<int>& rating) {
        int result = 0;
        const int MAX = 100000;
        vector<int> T1(MAX + 1, 0), T2(MAX + 1, 0);
        for (auto num : rating) {
            updateTree(T2, MAX - num + 1, 1);
        } 
        for (auto num : rating) {
            updateTree(T2, MAX - num + 1, -1);
            int cntBefore = countTree(T1, num - 1);
            int cntAfter = countTree(T2, MAX - num + 1 - 1);
            updateTree(T1, num, 1);
            result += cntBefore * cntAfter;
        }
        //
        T1.clear();
        T2.clear();
        T1.resize(MAX + 1, 0);
        T2.resize(MAX + 1, 0);
        //
        for (auto num : rating) {
            updateTree(T1, MAX - num + 1, 1);
        } 
        for (int i = rating.size() - 1; i >= 0; -- i) {
            int num = rating[i];
            updateTree(T1, MAX - num + 1, - 1);
            int cntBefore = countTree(T2, num - 1);
            int cntAfter = countTree(T1, MAX - num + 1 - 1);
            updateTree(T2, num, 1);
            result += cntBefore * cntAfter;
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary indexed tree
 * 
 * */
