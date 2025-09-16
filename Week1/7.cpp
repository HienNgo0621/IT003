#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void input(vector<int> &a){
    for (int &x : a)
        cin >> x;
}

int LinearSearch_from_left(const vector<int> &a, int x, int &cntl){
    for (int i = 0; i < a.size(); i ++){
        cntl ++;
        if (a[i] == x) return i;
    }
    return -1;
}

int LinearSearch_from_right(const vector<int> &a, int x, int &cntr){
    for (int i = a.size() - 1; i >= 0; i --){
        cntr ++;
        if (a[i] == x) return (a.size() - 1 - i);
    }
    return -1;
}

int main (){

    int n, cntl = 0, cntr = 0;
    cin >> n;
    vector<int> a(n, 0);
    input(a);
    int x;
    cin >> x;
    int result_left = LinearSearch_from_left(a, x, cntl);
    int result_right = LinearSearch_from_right(a, x, cntr);
    
    if (result_left != -1){
        cout << result_left << endl << endl;
        cout << cntl << endl << endl;
    
        cout << result_right << endl << endl;
        cout << cntr << endl;
    }
    else 
        cout << result_left << endl;

    system("pause");
    return 0;
}