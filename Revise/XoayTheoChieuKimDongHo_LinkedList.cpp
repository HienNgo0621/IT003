#include <iostream>
#include <limits>
#include <tuple>
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

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
        void printLinkedList();

};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


void SinglyLinkedList::printLinkedList() {
    SinglyLinkedListNode* cur = head;
    while (cur) {
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << '\n';
}

SinglyLinkedListNode* XoayCungChieu(SinglyLinkedList& a, int k)
{
    SinglyLinkedListNode* temp = a.head;
    for (int i = 0; i < k; i ++)
    {
        temp = temp -> next;
    }

    SinglyLinkedListNode* p = temp;
    SinglyLinkedListNode* save = temp;
    while(temp -> next != nullptr)
    {
        temp = temp -> next;
        if (temp -> next == nullptr)
        {
            temp -> next = a.head;
        }
        p -> next = temp -> next;
        if (temp -> next -> data == save -> data) break;
    }
    return p;
}

SinglyLinkedListNode* XoayCungChieu(SinglyLinkedListNode* &head, int k)
{
    if (!head || !head -> next || k == 0) return head;
    SinglyLinkedListNode* tail = head;
    int len = 1;
    while (tail -> next)
    {
        len ++;
        tail = tail -> next;
    }


    k%= len;
    if (k == 0) return head;

    tail -> next = head;
    SinglyLinkedListNode* newTail = head;
    for (int i = 0; i < len - k - 1; i ++)
    {
        newTail = newTail -> next;
    }
    SinglyLinkedListNode* newHead = newTail -> next;
    newTail -> next = nullptr;
    return newHead;
}

SinglyLinkedListNode* XoayNguocChieu(SinglyLinkedListNode* &head, int k)
{
    if (!head || !head -> next || k == 0) return head;
    SinglyLinkedListNode* tail = head;
    int len = 1;
    while (tail -> next)
    {
        len ++;
        tail = tail -> next;
    }
    if (k == 0) return head;
    k %= len;
    k = len - k;
    if (k == 0) return head;
    tail -> next = head;
    SinglyLinkedListNode* newTail = head;
    for (int i = 0; i < k; i ++)
    {
        newTail = newTail -> next;
    }
    SinglyLinkedListNode* newHead = newTail -> next;
    newTail -> next = nullptr;
    return newHead;
}

int main()
{
    int n; cin >> n;
    SinglyLinkedList llist;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        llist.insert_node(x);
    }
    int m; cin >> m;
    for (int i = 0; i < m ; i++)
    {
        int x; string a;
        cin >> x >> a;
        if (a == "CC") llist.head = XoayNguocChieu(llist.head, x);
        else llist.head = XoayCungChieu(llist.head, x);
        llist.printLinkedList();
    }
    return 0;
}

