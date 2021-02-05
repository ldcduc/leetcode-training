/* Problem url: https://leetcode.com/problems/minimize-deviation-in-array
 * Code by: ldcduc
 * */
/* Begin of Solution */
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int maxx = INT_MIN, minn = INT_MAX;
        priority_queue<int> Q;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] % 2) { // only 1 time possible
                nums[i] *= 2;
            }
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
            Q.push(nums[i]);
        }        
        int result = maxx - minn;
        while (Q.top() % 2 == 0) {
            int value = Q.top();
            Q.pop();
            result = min(result, value - minn);
            value /= 2;
            minn = min(minn, value);
            Q.push(value);
        } 
        result = min(result, Q.top() - minn);
        return result;
    }
};
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap, trick, hard
 * 
 * */
