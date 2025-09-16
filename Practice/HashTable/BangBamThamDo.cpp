#include<iostream>
using namespace std;

#define MAXTABLESIZE 1000
const int TableSize = 1000;

struct Node
{
    string password;
    string username;
};

typedef Node* HashTable[MAXTABLESIZE];

unsigned int HF(const string & key)
{
    unsigned int HashVal = 0;
    for (char ch : key)
    {
        HashVal = 37 * HashVal + ch;
    }
    return HashVal % TableSize;
}

int HF_LinearProbing(string key, int i)
{
    return (HF(key) + i) % TableSize;
}

int HF_QuadraticProbing(string key, int i)
{
    return (HF(key) + i * i) % TableSize;
}

void InitHash(HashTable &H, int& currentsize)
{
    currentsize = 0;
    for (int i = 0; i < TableSize; i ++)
    {
        H[i] = nullptr;
    }
}

bool isFull(int currentsize)
{
    return currentsize >= TableSize;
}

bool Insert(HashTable& H, int& currentsize, const string &user, const string &pass, bool quadratic = false)
{
    if(isFull(currentsize)) return false;

    Node* p = new Node{pass, user};
    int i = 0; int b = HF(user);
    while(H[b] != nullptr && H[b] -> username != user)
    {
        i ++;
        b = quadratic ? HF_QuadraticProbing(user, i) : HF_LinearProbing(user, i);
        if (currentsize >= TableSize) return false;
    }

    if (H[b] == nullptr)
    {
        H[b] = p;
        currentsize ++;
    }
    else {
        delete p;
        H[b] -> password = pass;
    }
    return true;
}

int Search(HashTable H, const string &key, bool quadratic = false)
{
    int b = HF(key), i = 0;
    while (H[b] != nullptr)
    {
        if (H[b] -> username == key) return b;
        else{
            i ++;
            b = quadratic ? HF_QuadraticProbing(key, i) : HF_LinearProbing(key, i);
            if (i >= TableSize) break;
        }
    }
    return -1;
}

bool Remove(HashTable &H, int &currentsize, const string &key, bool quadratic = false)
{
    int pos = Search(H, key, false);
    if (pos == -1) return false;
    delete H[pos];
    H[pos] = nullptr;
    currentsize --;
    return true;
}

void PrintPassword(HashTable H, int m, bool quadratic = false)
{
    for (int i = 0; i < m; i ++)
    {
        string user;
        cin >> user;
        int pos = Search(H, user, false);
        if (pos == -1) cout << "Khong tim thay tai khoan!\n";
        else cout << H[pos] -> password << endl;
    }
}

void Destroy(HashTable &H, int &currentsize)
{
    for (int i = 0; i < TableSize; i ++)
    {
        if (H[i]!= NULL) delete H[i];
        H[i] = nullptr;
    }
    currentsize = 0;
}

int main() {
    HashTable H;
    int CurrentSize;
    InitHash(H, CurrentSize);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string user, pass;
        cin >> user >> pass;
        Insert(H, CurrentSize, user, pass);
    }

    PrintPassword(H, m);
    Destroy(H, CurrentSize);
    return 0;
}
