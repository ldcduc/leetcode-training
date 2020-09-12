/* Problem url: https://leetcode.com/problems/longest-substring-without-repeating-characters
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        vector<int> positions[256];
        for (int c = 0; c < 256; ++ c) {
            positions[c].push_back(-1); 
        }
        int len = s.length();
        int maxPos = -1;
        for (int i = 0; i < len; ++ i) {
            maxPos = max(maxPos, positions[s[i]][0]);
            result = max(result, i - maxPos);
            positions[s[i]][0] = i;
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
