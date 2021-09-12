/* Problem url: https://leetcode.com/problems/slowest-key
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        pair<int, int> key = {releaseTimes[0], keysPressed[0]};
        for (int i = 1; i < keysPressed.size(); ++ i) key = max(key, {releaseTimes[i] - releaseTimes[i - 1], keysPressed[i]});
        return key.second;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: sort
 * 
 * */
