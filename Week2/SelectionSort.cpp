#include<iostream>
using namespace std;

void Print(int a[], int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl << endl;
}

void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int A[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i; // tạm thời xem A[i] là nhỏ nhất
        // Tìm phẩn tử nhỏ nhất trong đoạn từ A[i] đến A[n - 1]
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[min]) // A[j] mà nhỏ hơn A[min] thì A[j] là nhỏ nhất
                min = j; // lưu lại vị trí A[min] mới vừa tìm được
        if (min != i){ // nếu như A[min] không phải là A[i] ban đầu thì đổi chỗ
            swap(A[i], A[min]);
            Print(A, n);
        }
    }
}

int main(){
    int n; cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    SelectionSort(a, n);

    system("pause");
    return 0;
}