/* Problem url: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string smallestSubsequence(string s) {
        string result = "";
        vector<int> cnt(26, 0);
        vector<bool> unavailable(26, 0);
        for (auto c : s) {
            ++ cnt[c - 'a'];
        }
        for (auto c : s) {
            -- cnt[c - 'a'];
            if (!unavailable[c - 'a']) { // available
                while (!result.empty() && c < result.back() && cnt[result.back() - 'a']) { // 
                    unavailable[result.back() - 'a'] = false; // available again
                    result.pop_back();
                }
                result.push_back(c);
                unavailable[c - 'a'] = true;
            }
        }
        return result; 
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, stack
 * 
 * */
