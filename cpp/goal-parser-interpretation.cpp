/* Problem url: https://leetcode.com/problems/goal-parser-interpretation
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string interpret(string command) {
        string result = "";    
        int n = command.length();
        for (int i = 0; i < n; ++ i) {
            if (command[i] == 'G') {
                result += 'G';
            } else if (command[i] == '(' && command[i + 1] == ')') {
                ++ i; 
                result += 'o';
            } else {
                i += 3; 
                result += "al";
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
