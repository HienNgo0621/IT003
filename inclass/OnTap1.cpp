#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<stack>
using namespace std;

// int main(){
//     int k, n;
//     cin >> k >> n;
//     vector<string> sdt(n);
//     for (string &a : sdt){
//         cin >> a;
//     }
    
//     unordered_map<string, int> demSo;
//     for (int i = n - 1; i >= 0; i --){
//         demSo[sdt[i]]++;
//     }
//     int cnt = 0;
//     unordered_set<string> visited;
//     for (int i = n - 1; i >= 0; i --){
//         if (!visited.count(sdt[i])){
//         cnt ++;
//         if (demSo[sdt[i]] > 1) cout << sdt[i] << "(" << demSo[sdt[i]] << ") ";
//         else cout << sdt[i] << " ";
//         visited.insert(sdt[i]);
//         if (cnt == k) break;
//         }
//     }
    
//     system("pause");
//     return 0;
// }

struct Node {
    int data;
    Node* left;
    Node* right;
};

void funct(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";    // In gốc
    funct(root->right);           // Duyệt cây con bên phải
    funct(root->left);            // Duyệt cây con bên trái
}