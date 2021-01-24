/* Problem url: https://leetcode.com/problems/multiply-strings
 * Code by: ldcduc
 * */
/* Begin of Solution */
class ReverseIndexedSolution { // Easier
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int remainder = 0, len = len1 + len2;
        string result = "";
        vector<int> arr(len1 + len2 + 1, 0);
        for (int i = 0; i < len1 / 2; ++ i) {
            swap(num1[i], num1[len1 - i - 1]);
        }
        for (int j = 0; j < len2 / 2; ++ j) {
            swap(num2[j], num2[len2 - j - 1]);
        }
        for (int i = 0; i < len1; ++ i) {
            for (int j = 0; j < len2; ++ j) {
                arr[i + j] += (num1[i] - '0') * (num2[j] - '0');
                arr[i + j + 1] += arr[i + j] / 10;
                arr[i + j] %= 10;
            }
        }
        int start = len1 + len2 - 1;
        while (start > 0 && arr[start] == 0) {
            -- start;
        }
        for (int i = start; i >= 0; -- i) {
            result += arr[i] + '0';
        }
        return result;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int remainder = 0, len = len1 + len2;
        string result = "";
        vector<int> arr(len1 + len2, 0);
        for (int i = len1 - 1; i >= 0; -- i) {
            for (int j = len2 - 1; j >= 0; -- j) {
                int ii = len1 - i, jj = len2 - j;
                arr[len - (ii + jj - 1)] += (num1[i] - '0') * (num2[j] - '0');
                arr[len - (ii + jj - 1) - 1] += arr[len - (ii + jj - 1)] / 10;
                arr[len - (ii + jj - 1)] %= 10;
            }
        }
        int start = 0;
        while (start < arr.size() - 1 && arr[start] == 0) {
            ++ start;
        }
        for (int i = start; i < arr.size(); ++ i) {
            result += arr[i] + '0';
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
