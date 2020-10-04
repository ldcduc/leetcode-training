/* Problem url: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n) {
            int cnt = 1, val = nums[0];
            for (int i = 1; i < n; ++ i) {
                if (nums[i] == val) {
                    ++ cnt;    
                    if (cnt > 2) {
                        int j = i;
                        while (j < n - 1 && nums[j + 1] == val) {
                            ++ j; 
                        }
                        for (int k = 1; j + k < n; ++ k) {
                            nums[i + k - 1] = nums[j + k];    
                        }
                        n -= j - i + 1;
                        -- i;
                    }
                } else {
                    val = nums[i];
                    cnt = 1;
                }
            }
        }
        return n;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: adhoc
 * 
 * */
