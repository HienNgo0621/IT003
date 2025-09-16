#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i ++)
    {
        for (int j = 0; j < n - i - 1; j ++)
        {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

int main()
{
    int a[10] = {2, 5, 7, 3, 1, 4, 6, 9, 8, 11};
    bubbleSort(a, 10);
    for (int i = 0; i < 10; i ++)
    {
        cout << a[i] << endl;
    }
    return 0;
}


