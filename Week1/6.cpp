#include<iostream>
#include<vector>
using namespace std;

void input(vector<int> &a){
    for (int &x : a)
        cin >> x;
}

int BinarySearch(const vector<int> &a, int x, int &cnt){
    int l = 0, r = a.size() - 1;
    bool flag = false;
    while (l <= r){
        cnt ++;
        int m = (l + r) / 2;
        if (x == a[m]){
            flag = true;
            return m;
        }
        else if (x > a[m]) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main (){

    int n, cnt = 0;
    cin >> n;
    vector<int> a(n, 0);
    input(a);
    int x;
    cin >> x;
    int result = BinarySearch(a, x, cnt);
    cout << result << endl << endl;
    if (result != -1) cout << cnt << endl;

    system("pause");
    return 0;
}