#include<iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    int min_idx;
    for (int i = 0; i < n; i ++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j ++)
        {
            if (a[min_idx] > a[j]) min_idx = j;
        }
        swap(a[min_idx], a[i]);
    }
}

int main()
{
    int a[5] = {2, 5, 7, 3, 1};
    selectionSort(a, 5);
    for (int i = 0; i < 5; i ++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
