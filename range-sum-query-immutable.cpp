/* Problem url: https://leetcode.com/problems/range-sum-query-immutable
 * Code by: ldcduc
 * */
/* Begin of Solution */
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        for (auto num : nums) {
            sum.push_back(sum.back() + num);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: accumulated sum
 * 
 * */
