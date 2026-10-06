class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        regStack.push(val);

        if (minStack.empty()) {
            minStack.push(val);
            return;
        }

        int min = (minStack.top() < val) ? minStack.top() : val;

        minStack.push(min);
    }
    
    void pop() {
        regStack.pop();
        minStack.pop();
    }
    
    int top() {
        return regStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> regStack;
    std::stack<int> minStack;
};
