/* Problem url: https://leetcode.com/problems/third-maximum-number
 * Code by: ldcduc
 * */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }
        if (s.size() < 3) {
            return *(s.rbegin());
        }
        set<int>::reverse_iterator it = s.rbegin();
        ++ it;
        ++ it;
        return *it;
    }
};

class LongSolution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = -(1ll << 32), second = -(1ll << 32), third = -(1ll << 32);    
        bool found = false;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] > first) {
                if (first > second) {
                    if (second > third) {
                        found = true;
                        third = second;
                    }
                    second = first;
                } 
                first = nums[i];
            } else if (nums[i] < first && nums[i] > second) {
                if (second > third) {
                    found = true;
                    third = second;
                }
                second = nums[i];
            } else if (nums[i] < second && nums[i] > third) {
                found = true;
                third = nums[i];
            }
        }
        return (found && first > second && second > third) ? third : first;
    }
};
/*
 * Comment by ldcduc
 * Suggested tags: math, careful
 * 
 * */
