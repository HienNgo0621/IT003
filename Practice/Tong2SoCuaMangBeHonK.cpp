#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int* a;
    int n, k; cin >> n >> k;

    a = new int[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    sort(a, a + n); // cho so tang dan
    int start = 0; int end = n - 1;
    int money = 0;
    while (start < end){
        int x = a[start] + a[end];
        if (x <= k){ // neu tong hai so nho hon k
            money = max(money, x);
            start ++;
        }
        else end--; // neu tong hai so lon hon k
    }
    cout << money << endl;
    detele[] a;
    return 0;
}
