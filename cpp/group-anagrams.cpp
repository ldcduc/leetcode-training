/* Problem url: https://leetcode.com/problems/group-anagrams
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> M;
        for (auto str : strs) {
            vector<int> freq(26, 0);
            string encode = "";
            for (auto c : str) {
                ++ freq[c - 'a'];
            }
            for (int c = 0; c < 26; ++ c) {
                if (freq[c]) {
                    encode += to_string(freq[c]) + (char) (c + 'a');
                }    
            }
            M[encode].push_back(str);
        }
        for (auto [frequency, vector_] : M) {
            result.push_back(vector_);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: hash table
 * 
 * */
