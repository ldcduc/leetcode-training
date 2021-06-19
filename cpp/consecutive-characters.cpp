/* Problem url: https://leetcode.com/problems/consecutive-characters
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int maxPower(string s) {
        int result = 0, cnt = 0;
        s += '#';    
        int len = s.length();
        for (int i = len - 2; i >= 0; -- i) {
            cnt = s[i + 1] != s[i] ? 1 : cnt + 1;
            result = max(result, cnt);
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: ad-hoc
 * 
 * */
