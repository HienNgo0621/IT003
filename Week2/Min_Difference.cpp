#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Hàm Partition cho QuickSort
int Partition(vector<int> &v, int low, int high) {
    int pivot = v[high];  // Chọn phần tử cuối làm chốt
    int i = low - 1;        // Vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {  // neu v[j] nho hon pivot thi doi cho
            i++;
            Swap(v[i], v[j]);
        }
    }
    Swap(v[i + 1], v[high]);  // dua pivot ve dung vi tri
    return i + 1;
}

// Ham QuickSort de quy
void QuickSort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pi = Partition(v, low, high);
        QuickSort(v, low, pi - 1);
        QuickSort(v, pi + 1, high);
    }
}

void Difference( vector<int> &a, int n){
    QuickSort(a, 0, n - 1);
    int min = abs(a[1] - a[0]);
    for (int i = 1; i < n - 1; i ++){
            if (abs(a[i] - a[i + 1]) < min) min = abs(a[i] - a[i + 1]);
    }

    vector<int> v;
    for (int i = 0; i < n - 1; i ++){
        if (abs(a[i] - a[i + 1]) == min){
            v.push_back(a[i]);
            v.push_back(a[i + 1]);
        }
}
    for (int i = 0; i < v.size(); i ++){
        cout << v[i] << " ";
    }
}

int main (){
    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    Difference(a, n);

    system("pause");
    return 0;
}