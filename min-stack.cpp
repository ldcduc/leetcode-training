/* Problem url: https://leetcode.com/problems/min-stack
 * Code by: ldcduc
 * */
/* Begin of Solution */
class MinStack {
public:
    /** initialize your data structure here. */
    struct Data {
        int value, min_val;
        Data(int value, int min_val) {
            this->value = value;
            this->min_val = min_val;
        }
    };
    vector<Data> a;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if (a.empty()) {
            a.push_back(Data(x, x));
        } else {
            a.push_back(Data(x, min(a.back().min_val, x)));
        }
    }
    
    void pop() {
        a.pop_back(); 
    }
    
    int top() {
        return a.back().value; 
    }
    
    int getMin() {
        return a.back().min_val; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: implementation, array
 * 
 * */
