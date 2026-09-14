class MinStack {
public:
    stack<int> mins;
    stack<int> record;
    MinStack() {
        
    }
    
    void push(int val) {
        int top = mins.empty() ? val : mins.top();
        mins.push(std::min(top, val));
        record.push(val);
    }
    
    void pop() {
        record.pop();
        mins.pop();
    }
    
    int top() {
        return record.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
