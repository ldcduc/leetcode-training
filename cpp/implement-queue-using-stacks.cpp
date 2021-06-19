/* Problem url: https://leetcode.com/problems/implement-queue-using-stacks
 * Code by: ldcduc
 * */
/* Begin of Solution */
class MyQueue {
    stack<int> s1, s2;
    void populate_s2() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (s2.empty()) {
            populate_s2();
        }     
        int res = s2.top();
        s2.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            populate_s2();
        }     
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: stack
 * 
 * */
