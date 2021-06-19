/* Problem url: https://leetcode.com/problems/find-smallest-letter-greater-than-target
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1, result = letters[0];
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target < letters[m]) {
                result = letters[m];
                r = m - 1;    
            } else {
                l = m + 1;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */
