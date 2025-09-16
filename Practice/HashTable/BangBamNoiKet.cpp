#include<iostream>
using namespace std;

#define LOAD 1.0

struct Node
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

struct List
{
    Node* head;
    Node* tail;

    Node* createNode(int x)
    {
        Node* p = new Node(x);
        p -> next = nullptr;
        return p;
    }

    void createList()
    {
        head = tail = nullptr;
    }

    void addTail(int x)
    {
        Node* p = createNode(x);
        if (head == nullptr)
        {
            head = tail = p;
            return;
        }
        tail -> next = p;
        tail = p;
    }

    void deleteList()
    {
        Node* temp = head;
        while (temp)
        {
            Node* del = temp;
            temp = temp -> next;
            delete del;
        }
        head = tail = nullptr;
    }
};

struct HashTable
{
    int M; //kich thuoc bang bam
    int n; //so phan tu hien co
    List* table;
};

void createHashTable(HashTable &H, int m)
{
    H.M = m;
    H.n = 0;
    H.table = new List[m];
    for (int i = 0; i < m; i ++)
    {
        H.table[i].createList();
    }
}

int Hash(HashTable H, int key)
{
    return key % H.M;
}

bool Insert(HashTable& H, int key)
{
    if ((double)(H.n + 1) / H.M > LOAD) return false;
    int idx = Hash(H, key);
    Node* temp = H.table[idx].head;
    while (temp)
    {
        if (temp -> data == key) return false;
        temp = temp -> next;
    }

    H.table[idx].addTail(key);
    H.n ++;
    return true;
}

Node* Search(HashTable H, int key)
{
    int b = Hash(H, key);
    Node* temp = H.table[b].head;
    while (temp)
    {
        if (temp -> data == key) return temp;
        temp = temp -> next;
    }
    return nullptr;
}

bool Delete(HashTable &H, int key)
{
    int idx = Hash(H, key);
    Node* curr = H.table[idx].head;
    Node* prev = nullptr;

    while(curr)
    {
        if (curr -> data == key)
        {
            if (prev == nullptr)
            {
                H.table[idx].head = curr -> next;
                if (H.table[idx].tail == curr)
                {
                    H.table[idx].tail = nullptr;
                }
            }
            else
            {
                prev -> next = curr -> next;
                if (H.table[idx].tail == curr)
                {
                    H.table[idx].tail = prev;
                }
            }
            delete curr;
            H.n --;
            return true;
        }
        prev = curr;
        curr = curr -> next;
    }
    return false;
}

void printHashTable(HashTable H)
{
    for (int i = 0; i < H.M; i ++)
    {
        cout << "[" << i << "]: ";
        Node* temp = H.table[i].head;
        while(temp)
        {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        if (!temp) cout << "NULL";
        cout << endl;
    }
}

void deleteHashTable(HashTable& H)
{
    for (int i = 0; i < H.M; i ++)
    {
        H.table[i].deleteList();
    }
    delete[] H.table;
    H.M = H.n = 0;
}

int main() {
    HashTable ht;
    int m, n;
    cout << "Nhap kich thuoc bang bam m: ";
    cin >> m;
    createHashTable(ht, m);

    cout << "Nhap so luong phan tu muon chen n: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu:\n";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (!Insert(ht, x)) cout << "Khong the chen " << x << " (co the trung hoac vuot LOAD)\n";
    }

    cout << "\nBang bam sau khi chen:\n";
    printHashTable(ht);

    // ======== Tim kiem =========
    cout << "\nNhap khoa muon tim: ";
    int keySearch;
    cin >> keySearch;
    Node* found = Search(ht, keySearch);
    if (found) cout << "Tim thay khoa " << keySearch << " trong bang bam.\n";
    else cout << "Khong tim thay khoa " << keySearch << ".\n";

    // ======== Xoa =========
    cout << "\nNhap khoa muon xoa: ";
    int keyDel;
    cin >> keyDel;
    if (Delete(ht, keyDel)) cout << "Da xoa " << keyDel << " khoi bang bam.\n";
    else cout << "Khong tim thay " << keyDel << " de xoa.\n";

    cout << "\nBang bam sau khi xoa:\n";
    printHashTable(ht);

    deleteHashTable(ht);
    return 0;
}


