/* Problem url: https://leetcode.com/problems/to-lower-case
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); ++ i) {
            if ('A' <= str[i] && str[i] <= 'Z') {
                str[i] += 'a' - 'A';
            }
        }    
        return str;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string
 * 
 * */
