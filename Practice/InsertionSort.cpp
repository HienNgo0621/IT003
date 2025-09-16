#include<iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i ++)
    {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int a[10] = {2, 5, 7, 3, 1, 4, 6, 9, 8, 10};
    insertionSort(a, 10);
    for (int i = 0; i < 10; i ++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

