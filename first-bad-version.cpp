/* Problem url: https://leetcode.com/problems/first-bad-version
 * Code by: ldcduc
 * */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int result;
        long long l = 1, r = n;
        while (l <= r) {
            long long m = (l + r) >> 1;
            if (isBadVersion(m)) {
                result = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: binary search
 * 
 * */

