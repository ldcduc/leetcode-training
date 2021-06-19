/* Problem url: https://leetcode.com/problems/implement-stack-using-queues
 * Code by: ldcduc
 * */
/* Begin of Solution */
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q[2];
    int index;
    MyStack() {
        index = 0;  
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q[index].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if (q[index].size() == 1) {
            res = q[index].front();
        } else {
            int sz = q[index].size();
            for (int i = 1; i < sz; ++ i) {
                q[1 - index].push(q[index].front());
                q[index].pop();
            }
            res = q[index].front();
        }    
        q[index].pop();
        index = 1 - index;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res;
        if (q[index].size() == 1) {
            res = q[index].front();
        } else {
            int sz = q[index].size();
            for (int i = 1; i < sz; ++ i) {
                q[1 - index].push(q[index].front());
                q[index].pop();
            }
            res = q[index].front();
        }    
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q[0].empty() && q[1].empty();    
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: queue
 * 
 * */
