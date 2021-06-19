/* Problem url: https://leetcode.com/problems/add-strings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();    
        int minLen = min(len1, len2), remainder = 0;
        string result = "";
        for (int i = 1; i <= minLen; ++ i) {
            remainder += num1[len1 - i] - '0' + num2[len2 - i] - '0';
            result += remainder % 10 + '0';
            remainder /= 10;
        }
        int tmp = max(len1 - minLen, len2 - minLen);
        for (int i = tmp - 1; i >= 0; -- i) {
            if (len1 > len2) {
                remainder += num1[i] - '0';    
            } else {
                remainder += num2[i] - '0';    
            }
            result += remainder % 10 + '0';
            remainder /= 10;
        }
        if (remainder > 0) {
            result += remainder % 10 + '0';
        }
        for (int i = 0; i < result.length() / 2; ++ i) {
            swap(result[i], result[result.length() - i - 1]);
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
