
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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
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

Node * insert(Node * root, int data) {
    if (root == NULL){
        return new Node(data);
    }
    Node* temp = root;
    while(true){
    if (data < temp -> data){
        if (temp -> left == NULL){
            temp -> left = new Node(data);
            break;
        } 
        else temp = temp -> left;
    }
    else if (data >= temp -> data){
        if (temp -> right == NULL){
            temp -> right = new Node(data);
            break;
        }
        else temp = temp -> right;
    }

    }
    return root;
}
}; 

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
  
    myTree.preOrder(root);
    system("pause");
    return 0;
}