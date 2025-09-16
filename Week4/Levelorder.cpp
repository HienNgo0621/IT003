
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

    void levelOrder(Node *root) {
        vector<vector<int>> res;
        if (root == NULL) return;
        queue<Node*> q;
        q.push(root);
        int curlevel = 0;
        while (!q.empty()){
            int len = q.size();
            res.push_back({});
            for (int i = 0; i < len; i ++){
                Node *node = q.front();
                q.pop();

                res[curlevel].push_back(node -> data);
                if (node -> left != NULL){
                    q.push(node -> left);
                }
                if (node -> right != NULL){
                    q.push(node -> right);
                }
            }
            curlevel ++;
        }
        for (int i = 0; i < res.size(); i ++){
            for (int j = 0; j < res[i].size(); j ++){
                cout << res[i][j] << " ";
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
  
    myTree.levelOrder(root);

    return 0;
}