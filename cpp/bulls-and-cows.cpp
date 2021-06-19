/* Problem url: https://leetcode.com/problems/bulls-and-cows
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        int len = secret.length();
        int f[2][26] = {0};
        for (int i = 0; i < len; ++ i) {
            if (secret[i] == guess[i]) {
                ++bull;    
            } else {
                ++f[0][secret[i] - '0'];
                ++f[1][guess[i] - '0'];
            }
        }
        for (int digit = 0; digit < 10; ++ digit) {
            cow += min(f[0][digit], f[1][digit]);
        }
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: string, implementation
 * 
 * */
