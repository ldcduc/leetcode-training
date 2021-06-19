/* Problem url: https://leetcode.com/problems/string-matching-in-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.push_back(words[i]); 
                    break;
                }
            }
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
