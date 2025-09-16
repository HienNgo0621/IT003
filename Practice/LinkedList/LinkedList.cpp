#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};

struct List{
    Node* head;
    Node* tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }

    //tao node moi
    Node* createNode(int x)
    {
        Node* p = new Node(x);
        p -> next = NULL;
        return p;
    }

    //them vao dau danh sach
    void addHead(int x)
    {
        Node* p = createNode(x);
        if (head == NULL)
        {
            head = p;
            tail = head;
        }
        else
        {
            p -> next = head;
            head = p;
        }
    }

    //them vao cuoi danh sach
    void addTail(int x)
    {
        Node* p = new Node(x);
        p -> next = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else {
            tail -> next = p;
            tail = tail -> next; // tail = p;
        }
    }

    //in danh sach
    void printList()
    {
        Node* temp = head;
        while (temp)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    //chen vao vi tri k
    void insertNode(int x, int pos)
    {
        if (pos == 0)
        {
            addHead(x);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i ++)
        {
            temp = temp -> next;
        }
        if (temp == NULL) return;
        Node* p = createNode(x);
        p-> next = temp -> next;
        temp -> next = p;
        if (p -> next == NULL)
        {
            tail = p;
        }
    }

    //xoa dau danh sach
    void deleteHead()
    {
        if (head == nullptr) return;
        Node* temp = head;
        head = head -> next;
        delete temp;
    }

    //xoa cuoi danh sach
    void deleteTail()
    {
        if (head == nullptr) return;
        if (head -> next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp -> next -> next != nullptr)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        tail = temp;
        tail -> next = nullptr;
    }

    //xoa vi tri bat ki
    void deleteNode(int pos)
    {
        if (pos == 0)
        {
            deleteHead();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; i ++)
        {
            temp = temp -> next;
        }
        if(temp == nullptr) return;
        Node* del = temp -> next;
        temp -> next = del -> next;
        delete del;
    }

    //xoa gia tri bat ki: cach 1
    Node* removeElements(Node* head, int val)
    {
        Node* dummy = new Node(-1);
        dummy -> next = head;
        Node* curr = dummy;
        while (curr -> next)
        {
            if (curr -> next -> val == val)
            {
                Node* del = curr -> next;
                curr -> next = del -> next;
                delete del;
            }
            else
            {
                curr = curr -> next;
            }
        }
        Node* newHead = dummy -> next;
        delete dummy;
        return newHead;
    }

    //Cach 2
    ListNode* removeElements(ListNode* head, int val)
    {
        if (head == NULL) return NULL;
        while (head != NULL && head -> val == val)
        {
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }
        ListNode* curr = head;
        while (curr != nullptr && curr -> next != nullptr)
        {
            if (curr -> next -> val == val)
            {
                ListNode* del = curr -> next;
                curr -> next = del -> next;
                delete del;
            }
            else curr = curr -> next;
        }
        return head;
    }

    //tim chi so cua x
    int findNode(int x)
    {
        Node* temp = head;
        int idx = 0;
        while (temp)
        {
            if (temp -> data == x)
            {
                return idx;
            }
            idx ++;
            temp = temp -> next;
        }
        return -1;
    }

    //dao nguoc mang
    void reverselist()
    {
        if (head == nullptr) return;
        Node* curr = head;
        Node* nxt = nullptr;
        Node* prev = nullptr;
        while(curr)
        {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        tail = head;
        head = prev;
    }

    int countingNode()
    {
        int cnt = 0;
        if (head == NULL) return cnt;
        Node* temp = head;
        while (temp)
        {
            cnt ++;
            temp = temp -> next;
        }
        return cnt;
    }

    void releaseList()
    {
        if (head == NULL) return;
        Node* temp = head;
        Node* del = NULL;
        while (temp)
        {
            del = temp;
            temp = temp -> next;
            delete del;
        }
        head = tail = NULL;
    }

    void createEmptyList()
    {
        head = tail = NULL;
    }
};

int main()
{
    List list;
    int n;
    cout << "Nhap so luong phan tu: "; cin >> n;
    for (int i = 0; i < n; i ++)
    {
        int x; cin >> x;
        list.addTail(x);
    }
    cout << "Nhap so muon chen vao va vi tri cua so do: ";
    int k, pos;
    cin >> k >> pos;
    list.insertNode(k ,pos);

    cout << "Danh sach vua nhap: ";
    list.printList();

    list.reverselist();
    list.printList();
    cout << "So node trong danh sach: " << list.countingNode() << endl;
    list.releaseList();
    list.printList();
    cout << "So node trong danh sach: " << list.countingNode() << endl;
    return 0;
}
