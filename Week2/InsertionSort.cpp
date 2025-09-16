#include<iostream>
using namespace std;

void Print(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int A[], int n)
{
    int pos, x;
    for (int i = 1; i < n; i++)
    {
        x = A[i]; // lưu lại giá trị của x tránh bị ghi đè khi dịch chuyển các phần tử
        pos = i - 1;
        // tìm vị trí thích hợp để chèn x
        while (pos >= 0 && A[pos] > x)
        {
            // kết hợp với dịch chuyển phần tử sang phải để chừa chỗ cho x
            A[pos + 1] = A[pos];
            pos--;
            Print(A, n);
        }
        // chèn x vào vị trí đã tìm được
        A[pos + 1] = x;
        Print(A, n);
    }
}

int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    InsertionSort(a, n);

    system("pause");
    return 0;
}