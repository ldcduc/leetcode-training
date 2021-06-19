/* Problem url: https://leetcode.com/problems/can-place-flowers
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int> tmp(flowerbed);
        for (int i = 0; i < tmp.size(); ++ i) {
            if (!tmp[i] && (i == 0 || !tmp[i- 1]) && (i == tmp.size() - 1 || !tmp[i + 1])) {
                tmp[i] = 1;
                -- n;
            }
        }
        return n <= 0;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
