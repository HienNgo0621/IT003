#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

};




// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* createNode(int x)
{
    SinglyLinkedListNode* p = new SinglyLinkedListNode(x);
    p -> next = nullptr;
    return p;
}

void addTail(SinglyLinkedList &a, int x)
{
    SinglyLinkedListNode* p = createNode(x);
    if (a.head == nullptr) {
        a.head = a.tail = p;
        return;
    }
    a.tail -> next = p;
    a.tail = p;
}

void reverseList(SinglyLinkedList &a)
{
    if (a.head == nullptr) return;
    SinglyLinkedListNode* curr = a.head;
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* nxt = nullptr;
    while (curr)
    {
        nxt = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = nxt;
    }
    a.tail = a.head;
    a.head = prev;
}

void Print(SinglyLinkedList a)
{
    if (!a.head) return;
    SinglyLinkedListNode* temp = a.head;
    while(temp)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    SinglyLinkedList l;
    int n; cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        addTail(l, x);
    }

    reverseList(l);
    Print(l);
    return 0;
}
