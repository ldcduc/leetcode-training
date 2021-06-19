/* Problem url: https://leetcode.com/problems/letter-combinations-of-a-phone-number
 * Code by: ldcduc
 * */
class Solution {
public:
    vector<char> chars[10];
    vector<string> result;
    string digits;
    string s;

    void generate(int index, int len) {
        if (index == len) {
            result.push_back(s);
        } else {
            int num = digits[index] - '0';
            for (auto c : chars[num]) {
                s[index] = c;
                generate(index + 1, len);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        for (char c = 'a'; c <= 'c'; ++ c) {
            chars[2].push_back(c);
        }
        for (char c = 'd'; c <= 'f'; ++ c) {
            chars[3].push_back(c);
        }
        for (char c = 'g'; c <= 'i'; ++ c) {
            chars[4].push_back(c);
        }
        for (char c = 'j'; c <= 'l'; ++ c) {
            chars[5].push_back(c);
        }
        for (char c = 'm'; c <= 'o'; ++ c) {
            chars[6].push_back(c);
        }
        for (char c = 'p'; c <= 's'; ++ c) {
            chars[7].push_back(c);
        }
        for (char c = 't'; c <= 'v'; ++ c) {
            chars[8].push_back(c);
        }
        for (char c = 'w'; c <= 'z'; ++ c) {
            chars[9].push_back(c);
        }
        if (digits.length()) {
            for (int i = 0; i < digits.length(); ++ i) {
                s += ' ';
            }
            generate(0, digits.length());
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */

