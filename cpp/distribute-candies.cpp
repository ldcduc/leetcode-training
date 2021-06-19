/* Problem url: https://leetcode.com/problems/distribute-candies
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> s;
        int n = candyType.size();
        for (int i = 0; i < candyType.size(); ++ i) {
            s.insert(candyType[i]);
        }
        return n / 2 < s.size() ? n / 2 : s.size();
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: easy
 * 
 * */
