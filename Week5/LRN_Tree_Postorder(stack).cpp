
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void postOrder(Node *root) {
        stack<Node*> st;
        Node* curr = root;
        Node* lastVisited = NULL;
        while (curr != NULL || !st.empty()){
            if (curr){ // khong dung while vi di tu nhanh trai va con phai kiem tra nhanh phai xem co con phan tu khong
                st.push(curr);
                curr = curr -> left;
            } else {
                Node* peekNode = st.top(); // de luu cha lai
                // bat dau xu li ben nhanh phai
                if (peekNode -> right && lastVisited != peekNode -> right){
                    curr = peekNode -> right;
                } else {
                    cout << peekNode -> data << " ";  // in ra peekNode -> data vi curr luc nay dang tro toi NULL
                    lastVisited = peekNode;
                    st.pop();
                }

            }

        }
        

    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.postOrder(root);

    system("pause");
    return 0;
}