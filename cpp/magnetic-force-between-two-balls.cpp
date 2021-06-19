/* Problem url: https://leetcode.com/problems/magnetic-force-between-two-balls
 * Code by: ldcduc
 * */
class Solution {
public:
    bool check(vector<int>& position, int m, int expectedDistance) {
        int mTmp = m;
        int lastPosition = position[0];
        --mTmp;
        for (int i = 1; i < position.size() && mTmp > 0; ++ i) {
            if (position[i] - lastPosition >= expectedDistance) {
                --mTmp;
                lastPosition = position[i];
            }
        }
        if (mTmp == 0) {
            return true;
        }
        mTmp = m;
        lastPosition = position.back();
        for (int i = position.size() - 1; i >= 0; -- i) {
            if (lastPosition - position[i] >= expectedDistance) {
                --mTmp;
                lastPosition = position[i];
            }
        }
        return !mTmp;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        long long l = 1, r = position.back() - position[0];
        long long result = r;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (check(position, m, mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
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

