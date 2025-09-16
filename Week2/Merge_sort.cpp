#include<iostream>
#include<vector>
using namespace std;

void Print(const vector<int> &a, int left, int right){
    for (int i = 0; i < a.size(); i ++){
        if (i == left) cout << "[ ";
        cout << a[i] << " ";
        if (i == right) cout << "] ";
    }
    cout << endl;
}

void Merge(vector<int> &a, int left, int mid, int right){
    int n1 = mid - left + 1; // so phan tu mang trai
    int n2 = right - (mid + 1) + 1; // so pha tu mang phai
    
    // tao hai mang luu vao 
    vector<int> LeftArr(n1), RightArr(n2);

    // sao chep vao hai mang
    for (int i = 0; i < n1; i ++){
        LeftArr[i] = a[i + left];
    }

    for (int i = 0; i < n2; i ++){
        RightArr[i] = a[mid + 1 + i];
    }

    // current la vi tri hien tai cua mang a
    int i = 0, j = 0, current = left;

    // tron hai mang theo thu tu

    while (i < n1 && j < n2){
        if (LeftArr[i] <= RightArr[j]){
            a[current ++] = LeftArr[i ++];
        }
        else 
            a[current ++] = RightArr[j ++];

    }

    // neu mang con phan tu thi luu vao a[]

    while (i < n1){
        a[current ++] = LeftArr[i ++];
    }

    while (j < n2){
        a[current ++] = RightArr[j ++];
    }

    Print(a, left, right);

}

void MergeSort(vector<int> &a, int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        // sap mang 1
        MergeSort(a, left, mid);

        // sap mang 2
        MergeSort(a, mid + 1, right);

        //tron hai mang
        Merge(a, left, mid, right);
    }   
}

int main (){
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i ++){
        cin >> v[i];
    }

    MergeSort(v, 0, n - 1);

    

    system("pause");
    return 0;
}


