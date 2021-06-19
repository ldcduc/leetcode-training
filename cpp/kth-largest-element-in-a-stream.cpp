/* Problem url: https://leetcode.com/problems/kth-largest-element-in-a-stream
 * Code by: ldcduc
 * */
/* Begin of Solution */
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> Min;
    priority_queue<int, vector<int>, less<int>> Max;
    int k, size_min, size_max;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        size_min = 0;
        size_max = 0;
        for (auto num : nums) {
            if (size_min < k) {
                ++ size_min;
                Min.push(num);
            } else {
                ++ size_max;
                if (num > Min.top()) {
                    Max.push(Min.top());
                    Min.pop();
                    Min.push(num);
                } else {
                    Max.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if (size_min < k) {
            ++ size_min;
            Min.push(val);
        } else {
            ++ size_max;
            if (val > Min.top()) {
                Max.push(Min.top());
                Min.pop();
                Min.push(val);
            } else {
                Max.push(val);
            }
        }
        return Min.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: heap
 * 
 * */
