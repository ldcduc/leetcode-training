/* Problem url: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minDeletions(string s) {
        vector<int> f(26, 0);
        for (int i = 0; i < s.length(); ++ i) {
            ++ f[s[i] - 'a'];
        }
        sort(f.begin(), f.end());
        f.push_back(1e9);
        int result = 0;
        for (int i = 25; i >= 0; -- i) {
            if (f[i] > 0) {
                if (f[i] >= f[i + 1]) {
                    int t = f[i] - max(f[i + 1] - 1, 0);
                    result += t;
                    f[i] -= t;
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
