class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;
    int count;
    // using constructor to intialise the varaibles.
    MyCircularQueue(int k) {
        size=k;
        arr=new int[size];
        front =rear=-1;
        count=0;
    }
    
 
    
    bool enQueue(int value) {
        if (count == size) {
            return false; // Queue is full
        }

        rear++;
        if (rear == size) {
            rear = 0; // Wrap around
        }    
        arr[rear] = value;
        count++;
        if (front == -1) {
            front = 0;
        }
        return true;
    }

    
    bool deQueue() {
        // 
        if(front == -1)
        {
            return false;  // it is empty
        }
        
        if(front == rear)
        {
            front =rear =-1;
        }
        else if(front == size-1)
        {
            front =0;
        }
        else
        {
            front++;
        }
        count--;
        return true;
    }
    
    int Front() {
        if(front ==-1)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }

        
    }
    
    int Rear() {
        if(rear==-1)
        {
            return -1;
        }
        
        else
        {
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(count == 0)
        {
            return 1;  // it is empty
        }

        return 0;
        
    }
    
 
    bool isFull() {
        return (count == size);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */