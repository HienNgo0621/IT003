#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

struct Tinh{
    short ma;
    char ten[31];
    int danso;
    float dientich;

    void nhapTinh(){
        cin >> ma >> ten >> danso >> dientich;
    }
};

struct Node{
    Tinh data;
    Node* next;
    Node(Tinh x) : data(x), next(nullptr) {}
};

struct List{
    Node* head, *tail;
    List() : head(nullptr), tail(nullptr) {}

    void addHead(Tinh x){
        Node* p = new Node(x);
        if (!head) {
            head = tail = p;
            return;
        }
        p -> next = head;
        head = p;
    }
};

void input(){
    int n;
    cin >> n;
    List llist;
    for (int i = 0; i < n; i ++){
        Tinh x;
        x.nhapTinh();
        llist.addHead(x);
    }
}

void selectionSort(List& a){
    if (!a.head) return;
    for (Node* temp = a.head; temp != nullptr; temp = temp -> next){
        Node* max_idx = temp;
        for (Node* p = temp -> next;p != nullptr; p = p -> next){
            if (max_idx->data.ma < p->data.ma) max_idx = p;
        }
        swap(max_idx ->data, temp -> data);
    }
}

void print (List a){
    if (!a.head) return;
    Node* temp = a.head;
    while (temp){
        cout << temp->data.ma << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    List llist;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Tinh x;
        x.nhapTinh();
        llist.addHead(x);
    }

    cout << "\nDanh sach truoc khi sap xep:\n";
    print(llist);

    selectionSort(llist);

    cout << "\nDanh sach sau khi sap xep giam dan theo ma:\n";
    print(llist);
    system("pause");
    return 0;
}
