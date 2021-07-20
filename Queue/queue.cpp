#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Queue
{
    int qsize;
    int front, rear;
    vector<T> queue;

public:
    Queue(int qsize = 5)
    {
        queue = vector<T>(qsize);
        front = rear = -1;
        this->qsize = qsize;
    }
    bool empty()
    {
        return front == -1;
    }
    void push(T data)
    {
        if (rear == qsize - 1)
        {
            cout << "QUEUE IS FULL" << endl;
            return;
        }
        rear++;
        queue[rear] = data;

        if (front == -1)
            front++;
    }
    T peek()
    {
        if (empty())
        {
            cout << "QUEUE IS EMPTY" << endl;
            return INT_MIN;
        }
        return queue[front];
    }
    void pop()
    {
        if (empty() || front > rear)
        {
            front = rear = -1;
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }
        front++;
    }
    int size()
    {
        return qsize;
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    cout << myQueue.peek() << endl;
    cout << myQueue.empty() << endl;
    cout << myQueue.size() << endl;

    myQueue.pop();
}
