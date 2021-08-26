class MyCircularQueue {
    int *arr;
    int front,rear,size,capacity;
public:
    MyCircularQueue(int k) {
        front = 0,rear=-1;
        size = 0;
        capacity = k;
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear +1)%capacity;
        arr[rear] = value;
        size++;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front = (front  + 1)%capacity;
        size--;
        return true;
        
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[front];
    }
    
    int Rear() {
         return isEmpty() ? -1 : arr[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};
