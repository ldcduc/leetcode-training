/* Problem url: https://leetcode.com/problems/jewels-and-stones
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int result = 0;
        unordered_map<char, bool> M;
        for (auto c : J) {
            M[c] = true;
        }
        for (auto c : S) {
            result += M.count(c) > 0;
        } 
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */
