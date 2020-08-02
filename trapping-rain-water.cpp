/* Problem url: https://leetcode.com/problems/trapping-rain-water
 * Code by: ldcduc
 * */
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int result = 0;
        vector<int> lmax(height.size()), rmax(height.size());
        lmax[0] = height[0];
        for (int i=1; i<height.size(); ++i) {
            lmax[i] = max(lmax[i-1], height[i]);
        }
        rmax[height.size()-1] = height[height.size()-1];
        for (int i=height.size()-2; i>=0; --i) {
            rmax[i] = max(rmax[i+1], height[i]);
        }
        for (int i=0; i<height.size(); ++i) {
            result += min(lmax[i], rmax[i]) - height[i];
        }
        return result;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: dp, 
 * Be aware of the corner case
 * */
