/* Problem url: https://leetcode.com/problems/valid-parentheses
 * Code by: ldcduc
 * */
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_;
        int chars[255];
        chars['('] = 0;
        chars['['] = 0;
        chars['{'] = 0;
        chars[')'] = '(';
        chars[']'] = '[';
        chars['}'] = '{';
        for (auto char_ : s) {
            if (chars[char_] == 0) {
                stack_.push(char_);
            } else {
                if (!stack_.empty() && chars[char_] == stack_.top()) {
                    stack_.pop();
                } else {
                    return false;
                }
            }
        }
        return stack_.empty();
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */

