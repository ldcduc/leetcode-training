/* Problem url: https://leetcode.com/problems/repeated-dna-sequences
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() >= 10) {
            unordered_map<string, int> M;
            for (int i = 0; i < s.length() - 10 + 1; ++ i) {
                string str = s.substr(i, 10);
                ++ M[str];
                if (M[str] == 2) {
                    result.push_back(str);
                }
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, sub-string
 * 
 * */
