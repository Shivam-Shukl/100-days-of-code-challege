class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int, int> > s;
    int mini(int a, int b) { return a > b ? b : a; }
    void push(int val) {
        /* new max will be given no. if stack is empty else
        we compare given no. to max at current top of
        stack*/
        
        int new_min = s.empty()
                          ? val
                          : mini(val, s.top().second);
 
        // we push the pair of given_element,new_min in s
 
        s.push({ val, new_min });
    }
    
    
    void pop() {

        if (!s.empty()) {
            s.pop();
        }
        
    }
    
    int top() {
        if(!s.empty()){
            std::pair<int, int> topElement = s.top();
            int intValue = topElement.first; // or topElement.second, depending on your data 
            return intValue;

        }
      
        else 
        return INT_MIN;
    }
    
    int getMin() {


        int min_elem = s.top().second;
        return min_elem;
    }
};
