class MyQueue {
private:
    stack<int> data;
    stack<int> temp;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        data.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top;
        while(!data.empty())
        {
            top = data.top();
            data.pop();
            temp.push(top);
        }
        temp.pop();

        while(!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        int top;
        while(!data.empty())
        {
            top = data.top();
            data.pop();
            temp.push(top);
        }
        //temp.pop();

        while(!temp.empty())
        {
            data.push(temp.top());
            temp.pop();
        }
        return top;

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return data.empty();
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