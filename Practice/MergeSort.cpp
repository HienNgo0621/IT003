#include<iostream>
using namespace std;

void Merge(int a[], int left, int mid, int right)
{
    int *temp = new int [right - left + 1];
    int m = left;
    int n = mid + 1;
    int k = 0;
    while (m <= mid || n <= right)
    {
        if ((a[m] > a[n] && m <= mid) || n > right)
        {
            temp[k ++] = a[m ++];
        }
        else {
            temp[k ++] = a[n ++];
        }
    }
    for (int i = 0; i < k; i ++)
    {
        a[left + i] = temp[i];
    }
    delete[] temp;
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

void mergeSort(int a[], int n)
{
    mergeSort(a, 0, n - 1);
}

int main()
{
    int a[10] = {2, 5, 7, 3, 1, 4, 6, 9, 8, 11};
    mergeSort(a, 10);
    for (int i = 0; i < 10; i ++)
    {
        cout << a[i] << endl;
    }
    system("pause");
    return 0;
}



