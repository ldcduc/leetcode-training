/* Problem url: https://leetcode.com/problems/add-binary
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() > b.length()) {
            swap(a, b);
        }
        while (a.length() < b.length()) {
            a = '0' + a;
        }    
        int remainder = 0;
        string result = a;
        for (int i = a.length() - 1; i >= 0; -- i) {
            remainder += a[i] - '0' + b[i] - '0';
            result[i] = remainder % 2 + '0';
            remainder /= 2;
        }
        if (remainder > 0) {
            result = char('0' + remainder) + result;
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
