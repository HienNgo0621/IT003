
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

 void insert_node(SinglyLinkedList* &list, int node_data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!list -> head) { //list -> head = NULL
        list -> head = node;
    } else {
        SinglyLinkedListNode* temp = list -> head;
        while (temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = node;
    }
 }

void reverseLinkedList(SinglyLinkedList* &list){
    SinglyLinkedListNode* prev = NULL;
    SinglyLinkedListNode* curr = list -> head;
    SinglyLinkedListNode* next = curr -> next;

    while (curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    list -> head = prev;
 }

void printLinkedList(SinglyLinkedList* list){
    SinglyLinkedListNode* temp = list -> head;
    if (list -> head == NULL){
        return;
    }
    
    while (temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
 
int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;


    cin >> llist_count;

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

        insert_node(llist,llist_item);
    }
    
    
    reverseLinkedList(llist);
    printLinkedList(llist);
    system("pause");
    return 0;
}
