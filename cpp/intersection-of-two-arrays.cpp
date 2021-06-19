/* Problem url: https://leetcode.com/problems/intersection-of-two-arrays
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int index1 = 0, index2 = 0;
        while (index1 < nums1.size() && index2 < nums2.size()) {
            if (nums1[index1] == nums2[index2]) {
                if (result.empty() || nums1[index1] != result.back()) {
                    result.push_back(nums1[index1]);
                }
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
 * Suggested tags: sorting
 * 
 * */
