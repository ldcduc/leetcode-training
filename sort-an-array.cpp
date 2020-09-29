/* Problem url: https://leetcode.com/problems/sort-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int m = (l + r) >> 1;
            mergeSort(nums, l, m);
            mergeSort(nums, m + 1, r);
            // Merging
            int index1 = m, index2 = r;
            vector<int> tmp;
            for (int i = m + 1; i <= r; ++ i) {
                tmp.push_back(nums[i]);
            }
            while (tmp.size() && l <= index1) {
                if (tmp.back() >= nums[index1]) {
                    nums[index2 --] = tmp.back();
                    tmp.pop_back();
                } else {
                    nums[index2 --] = nums[index1 --];
                }
            }
            while (tmp.size()) {
                nums[index2 --] = tmp.back();
                tmp.pop_back();
            }
        }    
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: recursion
 * 
 * */
