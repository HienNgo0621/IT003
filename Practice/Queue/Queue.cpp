#include<iostream>
#define MAX 20
using namespace std;

struct Queue
{
    int front, rear;
    int a[MAX];

    Queue()
    {
        front = rear = -1;
    }

    void createQueue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }

    bool enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue overflow!\n";
            return false;
        }
        if(isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }
        a[rear] = x;
        return true;
    }

    bool dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!\n";
            return false;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            front = (front + 1) % MAX;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!\n";
            return -1;
        }
        return a[front];
    }

    int size()
    {
        if (isEmpty()) return 0;
        else if (rear >= front) return (rear - front + 1);
        else return MAX + rear - front + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!\n";
            return;
        }
        int i = front;
        while(true) //lap vo han den khi bi break
        {
            cout << a[i] << " ";
            if (rear == i) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 5; ++i) q.enqueue(i);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(6); q.enqueue(7); q.enqueue(8);
    q.display();
    return 0;
}
