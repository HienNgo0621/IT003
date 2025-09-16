#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left (nullptr), right (nullptr) {}
};

Node* makeNode(int x)
{
    return new Node(x);
}

void init(Node* root)
{
    root -> left = root -> right = nullptr;
}

Node* insertNode(Node* root, int x)
{
    if (!root)
    {
        return makeNode(x);
    }
    if (x > root -> data) root -> right =  insertNode(root -> right, x);
    else if (x < root -> data) root -> left = insertNode(root -> left, x);
    return root;
}

Node* searchNode(Node* root, int x)
{
    if (!root || root -> data == x) return root;
    else if (root -> data > x) return searchNode(root -> left, x);
    else return searchNode(root -> right, x);
}

int lowerbound(Node* root, int x)
{
    int ans = -1;
    while(root)
    {
        if (root -> data < x)
        {
            ans = root -> data;
            root = root -> right;
        } else
        {
            root = root -> left;
        }
    }
    return ans;
}

int upperbound(Node* root, int x)
{
    int ans = -1;
    while(root)
    {
        if (root -> data > x)
        {
            ans = root -> data;
            root = root -> left;
        } else root = root -> right;
    }
    return ans;
}

void LNR(Node* root)
{
    if (root)
    {
        LNR(root -> left);
        cout << root -> data << " ";
        LNR(root -> right);
    }
}
void NLR(Node* root)
{
    if (root)
    {
        cout << root -> data << " ";
        NLR(root -> left);
        NLR(root -> right);
    }
}

void LRN(Node* root)
{
    if (root)
    {
        LRN(root -> left);
        LRN(root -> right);
        cout << root -> data << " ";
    }
}

int height(Node* root)
{
    if (root == NULL) return 0;
    return 1 + max(height(root -> left), height(root -> right));
}

int checkBalance(Node* root)
{
    if (!root)
    {
        cout << "Empty Tree\n";
        return 0;
    }

    int leftHeight = height(root -> left);
    int rightHeight = height(root -> right);

    if (leftHeight < rightHeight) return 1;
    else if (leftHeight > rightHeight) return -1;
    else return 0;
}

void replaceNode(Node* &root, Node* &p) //root la node thay the, p la node can duoc thay the
{
    if (root -> right != nullptr)
    {
        replaceNode(root -> right, p); //lon nhat cua cay con ben trai
    }
    else
    {
        cout << "Node thay the: " << root -> data << endl;
        p -> data = root -> data;
        p = root;
        root = root -> left;
    }
}

void deleteNode(Node* &root, int x)
{
    if (!root) return;
    if (x < root -> data) deleteNode(root -> left, x);
    else if (x > root -> data) deleteNode(root -> right, x);
    else
    {
        Node* p = root;
        //TH1; node co 1 con
        if (!root -> left) root = root -> right;
        else if (!root -> right) root = root -> left;
        //TH2: node co 2 con
        else
        {

            replaceNode(root -> left, p);
        }
        delete p;
    }
}


int main() {
    Node* root = NULL;
    int x;

    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    cout << "Cay BST sau khi them: ";
    LNR(root);
    cout << endl;

    int val = 40;
    Node* found = searchNode(root, val);
    if (found) cout << "Tim thay " << val << " trong cay.\n";
    else cout << "Khong tim thay " << val << ".\n";

    cout << "Xoa node 50 (co 2 con):\n";
    deleteNode(root, 50);

    cout << "Cay BST sau khi xoa: ";
    LNR(root);
    cout << endl;
    cout << checkBalance(root);


    return 0;
}
