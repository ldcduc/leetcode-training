/* Problem url: https://leetcode.com/problems/convert-a-number-to-hexadecimal
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    char ch[16];
    Solution() {
        for (char i = '0'; i <= '9'; ++ i) {
            ch[i - '0'] = i;
        }
        for (char i = 'a'; i <= 'f'; ++ i) {
            ch[i - 'a' + 10] = i;
        }
    }
    string toHex(int num) {
        if (num) {
            string result = "";
            long long maskOne = 15ll << 28;
            int cnt = 28;
            for (; (num & maskOne) >> cnt == 0; maskOne >>= 4, cnt -= 4);
            for (; cnt >= 0; cnt -= 4, maskOne >>= 4) {
                result += ch[(num & maskOne) >> cnt];
            }
            return result; 
        } else {
            return "0";
        }
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bit manipulation
 * 
 * */
