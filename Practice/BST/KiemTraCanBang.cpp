/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
include
###End banned keyword*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TNode
{
    int key;
    TNode *left, *right;
};

typedef TNode *TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE)
{
    int i;
    TREE root;
    if (inE < inB)
        return NULL;
    root = new TNode;
    if (root != NULL)
    {
        root->key = pre[preB];
        for (i = inB; i <= inE; i++)
            if (in[i] == pre[preB])
                break;
        root->left = CreateTree(pre, in, preB + 1, preE, inB, i - 1);
        root->right = CreateTree(pre, in, preB + i - inB + 1, preE, i + 1, inE);
    }
    return root;
}

void Input(vector<int> &v)
{
    int tmp;
    cin >> tmp;
    while (tmp > 0)
    {
        v.push_back(tmp);
        cin >> tmp;
    }
}
void postOrder(TNode *root)
{
    if (root == NULL)
    {
        cout << "-1 ";
        return;
    }
    cout << root->key << " ";
    postOrder(root->left);
    postOrder(root->right);
}
// ###INSERT CODE HERE -

int height(TREE root)
{
    if (!root) return -1;
    return 1 + max(height(root -> right), height(root -> left));
}

void Fun(TREE root)
{
    if (root == nullptr)
    {
        cout << "Empty Tree";
        return;
    }

    int leftheight = height(root -> left);
    int rightheight = height(root -> right);
    if (leftheight > rightheight) cout << "-1";
    else if (leftheight < rightheight) cout << "1";
    else cout << "0";
}

int main()
{
    vector<int> duyetNLR;
    vector<int> duyetLNR;
    Input(duyetNLR);
    Input(duyetLNR);
    int Num = duyetNLR.size() - 1;
    TREE root = CreateTree(duyetNLR, duyetLNR, 0, Num, 0, Num);
    Fun(root);
    system("pause");
    return 0;
}
