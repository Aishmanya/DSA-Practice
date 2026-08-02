// Problem: Min Stack
// Link: https://leetcode.com/problems/min-stack/
// Time: O(1) for all operations
// Space: O(n)

// Approach:
// Maintain two stacks: mainStack for standard stack operations, 
// and minStack to keep track of the minimum value present at each state level.

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {
        // Constructor: Initializer
    }
    
    void push(int val) {
        mainStack.push(val);
        
        // If minStack is empty, the current value is the minimum.
        // Otherwise, push the minimum between current val and current min.
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            minStack.push(std::min(val, minStack.top()));
        }
    }
    
    void pop() {
        // Pop from both stacks to maintain state sync
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top(); // Returns current minimum in O(1)
    }
};

/**
 * Your MinStack object will be instantiated and called as such:-
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */