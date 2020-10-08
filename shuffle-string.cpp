/* Problem url: https://leetcode.com/problems/shuffle-string
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result = s;    
        for (int i = 0; i < indices.size(); ++ i) {
            result[indices[i]] = s[i];
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
