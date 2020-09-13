/* Problem url: https://leetcode.com/problems/buddy-strings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool buddyStrings(string A, string B) {
        int len;
        if ((len = A.length()) == B.length()) {
            vector<int> tmp;
            for (int i = 0; i < len; ++ i) {
                if (A[i] != B[i]) {
                    tmp.push_back(i);
                }
            }
            if (tmp.size() == 0) {
                int c[26] = {0};
                for (int i = 0; i < len; ++ i) {
                    if (c[A[i] - 'a']++) {
                        return true;
                    }
                }
            } else if (tmp.size() == 2) {
                return (A[tmp[0]] == B[tmp[1]] && A[tmp[1]] == B[tmp[0]]);
            }
        }    
        return false;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */
