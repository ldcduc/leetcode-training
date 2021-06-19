/* Problem url: https://leetcode.com/problems/verifying-an-alien-dictionary
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool compare(string& s1, string& s2, unordered_map<char, int>& M) {
        int i, length = min(s1.length(), s2.length());
        for (i = 0; i < length; ++ i) {
            int t1 = M[s1[i]], t2 = M[s2[i]];
            if (t1 != t2) {
                return t1 < t2;
            } 
        }
        return s1.length() < s2.length();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> M;
        for (int i = 0; i < 26; ++ i) {
            M[order[i]] = i;
        }
        for (int i = 1; i < words.size(); ++ i) {
            if (compare(words[i], words[i - 1], M)) {
                 return false;
            }
        }
        return true;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
