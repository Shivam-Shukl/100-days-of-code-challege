#include<stack>
#include<queue>
class MyQueue {
private:
    stack<int> s;

    void reverse(stack<int> &stk){
    
        stack<int> temp_stack;
        while (!stk.empty()) {
            int top_element = stk.top();
            stk.pop();
            temp_stack.push(top_element);
        }
        stk = temp_stack; // Reassign the reversed stack
    }

public:
    MyQueue() {
             
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if (s.empty()) {
            // Handle empty stack case
            return -1; // Return a default value or throw an exception
        }
        reverse(s);
        int element = s.top();
        s.pop();
        reverse(s);
        return element;
    }
    
    int peek() {
        if (s.empty()) {
            // Handle empty stack case
            return 0; // Return a default value or throw an exception
        }
        reverse(s);
        int element = s.top();
        reverse(s); // Re-reverse to maintain the original stack
        return element;
    }
    
    bool empty() {
        return s.empty();
    }
};