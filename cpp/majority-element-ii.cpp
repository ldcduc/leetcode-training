/* Problem url: https://leetcode.com/problems/majority-element-ii
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer–Moore majority vote algorithm
        vector<int> result;
        int major1, major2, count1 = 0, count2 = 0;
        for (auto num : nums) {
            if (count1 && num == major1) {
                ++ count1;
            } else if (count2 && num == major2) {
                ++ count2;
            } else if (count1 == 0) {
                count1 = 1;
                major1 = num;
            } else if (count2 == 0) {
                count2 = 1;
                major2 = num;
            } else {
                -- count1;
                -- count2;
            }
        }
        count1 = count2 = 0;
        for (auto num : nums) {
            count1 += num == major1;
            count2 += num == major2;
        }
        int tmp = nums.size() / 3;
        if (count1 > tmp) {
            result.push_back(major1);
        }
        if (count2 > tmp) {
            result.push_back(major2);
        }
        if (result.size() == 2 && result.back() == result[0]) {
            result.pop_back();
        }
        return result;
    }
};
class NaïveSolution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();    
        unordered_map<int, int> M;
        for (int i = 0; i < n; ++ i) {
            ++ M[nums[i]];
        }
        for (int i = 0; i < n; ++ i) {
            if (M[nums[i]] > n / 3) {
                result.push_back(nums[i]);
                M[nums[i]] = 0;
            }
        }
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
