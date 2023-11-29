class Node {
public:
    int val;
    int minVal; 
    Node *next;

    Node(int x) {
        val = x;
        next = nullptr;
        minVal = x; 
    }
};

class MinStack {
private:
    Node *start;

public:
    MinStack() {
        start = nullptr;
    }

    void push(int val) {
        Node *temp = new Node(val);
        if (!temp) {
            return;
        }

        if (start == nullptr || val < start->minVal) {
            temp->minVal = val;
        } else {
            temp->minVal = start->minVal;
        }

        temp->next = start;
        start = temp;
    }

    void pop() {
        if (!start) {
            return;
        }
        Node *temp = start;
        start = start->next;
        delete temp;
    }

    int top() {
        if (!start) {
            return 0;
        }
        return start->val;
    }

    bool empty() {
        return start == nullptr;
    }

    int getMin() {
        if (!start) {
            return 0; 
        }
        return start->minVal;
    }
};
