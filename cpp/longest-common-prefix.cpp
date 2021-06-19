/* Problem url: https://leetcode.com/problems/longest-common-prefix
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for (int i = 0; ; ++ i) {
            for (auto str : strs) {
                if (i == str.length() || str[i] != strs[0][i]) {
                    return result;
                }
            }
            result += strs[0][i];
        }    
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
