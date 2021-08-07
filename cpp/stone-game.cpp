/* Problem url: https://leetcode.com/problems/stone-game
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int xorSum = 0;
        for (int i = 0; i < piles.size(); ++ i) {
            xorSum ^= piles[i];
        }
        cout << xorSum << endl;
        return xorSum != 0;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: game theory, xor
 * 
 * */
