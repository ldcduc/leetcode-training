/* Problem url: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cntResult = 0, open = 0;
        vector<bool> eliminate(s.length(), false);
        stack<int> parenthesis;
        for (int i = 0; i < s.length(); ++ i) {
            if (s[i] == '(') {
                parenthesis.push(i);
                ++ open;
            } else if (s[i] == ')') {
                if (open) {
                    -- open;
                    parenthesis.pop();
                } else {
                    ++ cntResult;
                    eliminate[i] = true;
                }
            }
        }    
        //cntcntResult += open;
        while (!parenthesis.empty()) {
            eliminate[parenthesis.top()] = true;
            parenthesis.pop();
        }
        string result = "";
        for (int i = 0; i < s.length(); ++ i) {
            if (!eliminate[i]) {
                result += s[i];
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack
 * 
 * */
