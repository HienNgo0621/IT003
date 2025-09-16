#include<iostream>
#include<algorithm>
using namespace std;

bool kiemTraPhanTuTrungLap(int a[], int n){
    for (int i = 0; i < n - 1; i ++){
        if(a[i] == a[i + 1]) return 1;
    }
    return 0;
}

int main(){
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a, a + n);
    if (kiemTraPhanTuTrungLap(a, n) == 1) cout << "1";
    else cout << "0";
    return 0;
}
