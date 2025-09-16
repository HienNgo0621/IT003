#include<iostream>
#define MAX 20
using namespace std;

struct Stack
{
    int top;
    int a[MAX];

    Stack()
    {
        top = -1;
    }

    void createStack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX - 1   ;
    }

    bool push(int x)
    {
        if(isFull())
        {
            cout << "Stack overflow!" << endl;
            return false;
        }
        a[++ top] = x;
        return true;
    }

    bool pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return false;
        }
        top --;
        return true;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        return a[top];
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!\n";
            return;
        }

        for (int i = 0; i < size(); i ++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    //s.push(10);
    //s.push(5);
    //s.push(9);
    //s.push(11);
    //s.push(2);
    s.display();
    cout << "\nTop: " << s.peek() << endl;
    s.pop();
    cout << "Top after pop: " << s.peek() << endl;
    return 0;
}
