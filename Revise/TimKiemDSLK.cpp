#include<iostream>
using namespace std;

struct Point3D
{
    float x, y, z;

    friend istream& operator >> (istream& in, Point3D& a)
    {
        in >> a.x >> a.y >> a.z;
        return in;
    }

    bool operator == (const Point3D &a)
    {
        return x == a.x && y == a.y && z == a.z;
    }

    bool operator > (const Point3D &a)
    {
        if (x != a.x) return x > a.x;
        if (y != a.y) return y > a.y;
        return z < a.z;
    }
};

struct Node
{
    Point3D data;
    Node* next;
    Node(Point3D val) : data(val), next(nullptr) {}
};

struct List
{
    Node *head, *tail;

    void createList()
    {
        head = tail = nullptr;
    }

    Node* createNode(Point3D x)
    {
        Node* p = new Node(x);
        p -> next = nullptr;
        return p;
    }

    void addTail(Point3D x)
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

    int Search(Point3D x)
    {
        int cnt = 0;
        if (head == nullptr) return -1;
        Node* temp = head;

        while (temp)
        {
            if (temp -> data == x) return cnt;
            temp = temp -> next;
            cnt ++;
        }
        return -1;
    }
};

void run()
{
    int n; cin >> n;
    List list;
    list.createList();
    for (int i = 0; i < n; i ++)
    {
        Point3D a;
        cin >> a.x >> a.y >> a.z;
        list.addTail(a);
    }


    int m; cin >> m;
    for (int i = 0; i < m; i ++)
    {
        Point3D a;
        cin >> a.x >> a.y >> a.z;
        if (list.Search(a) != -1) cout << list.Search(a) << endl;
        else cout << "KHONG" << endl;
    }

}

int main()
{
    run();
    return 0;
}
