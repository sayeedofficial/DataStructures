#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
public:
    /** Initialize your data structure here. Set the capcity of the deque to be k. */
    vector<int> queue;
    int front, rear, size, capcity;

    MyCircularDeque(int capcity)
    {
        this->capcity = capcity;
        front = rear = -1;
        queue = vector<int>(capcity);
        size = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + capcity) % capcity;
        }
        queue[front] = value;
        size++;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1 + capcity) % capcity;
        }
        queue[rear] = value;
        size++;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1 + capcity) % capcity;
        size--;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (rear - 1 + capcity) % capcity;
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        return isEmpty() ? -1 : queue[front];
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        return isEmpty() ? -1 : queue[rear];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return size == capcity;
    }
};

int main()
{

    int k;
    cin >> k;

    MyCircularDeque *obj = new MyCircularDeque(k);
    int value;
    cin >> value;
    bool param_1 = obj->insertFront(value);
    bool param_2 = obj->insertLast(value);
    bool param_3 = obj->deleteFront();
    bool param_4 = obj->deleteLast();
    int param_5 = obj->getFront();
    int param_6 = obj->getRear();
    bool param_7 = obj->isEmpty();
    bool param_8 = obj->isFull();

    cout<<param_1<<endl;
    cout<<param_2<<endl;
    cout<<param_3<<endl;
    cout<<param_4<<endl;
    cout<<param_5<<endl;
    cout<<param_6<<endl;
    cout<<param_7<<endl;
    cout<<param_8<<endl;

}