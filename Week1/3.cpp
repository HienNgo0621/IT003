#include<iostream>
#include<vector>
using namespace std;

void input(vector<int> &a){
    for (int &x : a)
        cin >> x;
}

void BinarySearch(vector<int> a, vector<int> b){
    for (int i = 0; i < b.size(); i ++){
        bool flag = false;
        for (int j = 0; j < a.size(); j ++){
            if (b[i] == a[j]){
                flag = true;
                break;
            }
        }
        if (flag == true) cout << "YES" << endl;
        else    
            cout << "NO" << endl;
    }
}

int main (){

    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    vector<int> b(q, 0);

    input(a);
    input(b);

    BinarySearch(a, b);

    system("pause");
    return 0;
}