/* Problem url: https://leetcode.com/problems/intersection-of-two-arrays-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size(), index1 = 0;
        int n = nums2.size(), index2 = 0;
        vector<int> result;
        while (index1 < m && index2 < n) {
            if (nums1[index1] == nums2[index2]) {
                result.push_back(nums1[index1]);
                ++ index1;
                ++ index2;
            } else if (nums1[index1] < nums2[index2]) {
                ++ index1;
            } else {
                ++ index2;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: array
 * 
 * */
