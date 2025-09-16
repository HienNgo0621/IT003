#include<iostream>
#include<vector>
using namespace std;

void input(vector<int> &a){
    for (int &x : a)
        cin >> x;
}

void BinarySearch(vector<int> a, int x){
    vector<int> position;

    int cnt_x = 0;
    int k = 0, j = 0;
    bool flag = false;
    for (int i = 0; i < a.size(); i ++){
        if (x == a[i]){
            flag = true;
            cnt_x ++;
            position.push_back(i);
        }
        
    }
    if (flag == true){
        cout << cnt_x << endl;
        cout << endl;
        for (int i : position){
            cout << i << " " << i + 1 << endl << endl;
        }
    }
    else 
        cout << cnt_x << endl;
}

int main (){

    int n;
    cin >> n;
    vector<int> a(n, 0);
    input(a);
    int x;
    cin >> x;

    BinarySearch(a, x);

    system("pause");
    return 0;
}