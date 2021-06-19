/* Problem url: https://leetcode.com/problems/kth-largest-element-in-an-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class SimpleSolution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> Q;
        for (auto num : nums) {
            Q.push(num);
        }
        for (int i = 1; i < k; ++ i) {
            Q.pop();
        }
        return Q.top();
    }
};
class LinearSolution {
public:
    int recursion(vector<int>& nums, int l, int r, int k) {
        int mid = (l + r) >> 1;
        int pivot = nums[mid];
        int i = l, j = r;
        while (i <= j) {
            while (nums[i] > pivot) ++ i;
            while (nums[j] < pivot) -- j;
            if (i <= j) {
                swap(nums[i], nums[j]);
                if (i == mid) {
                    mid = j;
                } else if (j == mid) {
                    mid = i;
                }
                ++ i;
                -- j;
            }
        }
        if (k <= j) {
            return recursion(nums, l, j, k);
        } else if (k >= i) {
            return recursion(nums, i, r, k);
        }
        return nums[k];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return recursion(nums, 0, nums.size() - 1, k - 1);
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
