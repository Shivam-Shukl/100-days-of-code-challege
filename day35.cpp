class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int size;
    
    MyCircularDeque(int k) {
        size =k;
        arr=new int[size];
        front=rear =-1;
        
    }
    
    bool insertFront(int value) {

        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
        {
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        return true;
        
    }
    
    bool insertLast(int value) {
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
        {
            
            return false;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if (front == -1)
        {
            
            return false;
        }

        int data = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
            front = 0;
        else
            front++;
        
        return true;
    }
    
    bool deleteLast() {
        if (front == -1)
        {
            return false;
        }
        

        // Deque has only one element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
        
        return true;

    }
    
    int getFront() {
        if(front ==-1)
        {
            return -1;
        }
        else
        {
            return arr[front];
        }

    }
    
    int getRear() {
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
        if(front ==-1)
        {
            return 1;
        }
        else{
           return 0; 
        }
        
    }
    
    bool isFull() {
        if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
        {
            return 1;
        }
        else{
           return 0; 
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */