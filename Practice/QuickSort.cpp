#include<iostream>
using namespace std;

int Partition(int a[], int left, int right)
{
    int pivot = a[right];
    int id = left - 1;
    for (int i = left; i < right; i ++)
    {
        if (a[i] > pivot)
        {
            id ++;
            swap(a[id], a[i]); //gom nhung phan tu nho hon pivot ve dau day
        }
    }
    id ++; //de pivot ve dung vi tri
    swap(a[id], a[right]);
    return id;
}

void quickSort(int a[], int left, int right)
{
    if (left >= right) return;
    int id_pivot = Partition(a, left, right);
    quickSort(a, left, id_pivot - 1);
    quickSort(a, id_pivot + 1, right);
}

void quickSort(int a[], int n)
{
    quickSort(a, 0, n - 1);
}

int main()
{
    int a[10] = {2, 5, 7, 3, 1, 4, 6, 9, 8, 11};
    quickSort(a, 10);
    for (int i = 0; i < 10; i ++)
    {
        cout << a[i] << endl;
    }
    system("pause");
    return 0;
}



