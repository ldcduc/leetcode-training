/* Problem url: https://leetcode.com/problems/count-and-say
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string say(string s) {
        string result = "";
        int cnt = 0;
        char digit = s[0];
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == digit) {
                ++ cnt;
            } else {
                result += to_string(cnt) + digit;
                cnt = 1;
                digit = s[i];
            }
        }
        if (cnt > 0) {
            result += to_string(cnt) + digit;
        }
        return result;
    }
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            string result = "1";
            for (int i = 2; i <= n; ++ i) {
                result = say(result);
            }
            return result;
        }    
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
