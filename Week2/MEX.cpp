#include<iostream>
using namespace std;

int FindMEX(int a[], int n){
    bool exist[n + 1] = {false};
    for (int i = 0; i < n; i ++){
        if (a[i] >= 0 & a[i] <= n){
            exist[a[i]] = true;
        }
    }
    for (int i = 0; i < n; i ++){
        if (!exist[i]) return i;
    }
    return n;
}

int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

    cout << FindMEX(a, n);

    system("pause");
    return 0;
}