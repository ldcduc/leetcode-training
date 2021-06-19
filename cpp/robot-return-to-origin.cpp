/* Problem url: https://leetcode.com/problems/robot-return-to-origin
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool judgeCircle(string moves) {
        int R, L, U, D;
        R = L = U = D = 0;
        for (auto move : moves) {
            switch (move) {
                case 'R':
                    ++ R;
                    break;
                case 'L':
                    ++ L;
                    break;
                case 'U':
                    ++ U;
                    break;
                case 'D':
                    ++ D;
            }
        }      
        return (R == L && U == D);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
