#include<iostream>
using namespace std;

void Print(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int A[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (A[j] > A[j + 1]){
                Swap(A[j], A[j + 1]); // đổi chỗ A[j] và A[j + 1] //nho la j nhaaaa
                Print(A, n);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    BubbleSort(a, n);

    system("pause");
    return 0;
}