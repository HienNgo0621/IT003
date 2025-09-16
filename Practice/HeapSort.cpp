#include<iostream>
using namespace std;

//max - heap

void max_heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[largest] < a[left]){
        largest = left;
    }
    if (right < n && a[largest] < a[right]){
        largest = right;
    }
    if (largest != i){
        swap(a[largest], a[i]);
        max_heapify(a, n, largest);
    }
}

void maxHeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >=0; i --)
    {
        max_heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i --)
    {
        swap(a[0], a[i]);
        max_heapify(a, i, 0);
    }
}

// min - heap
void min_heapify(int a[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[smallest] > a[left])
    {
        smallest = left;
    }
    if (right < n && a[smallest] > a[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(a[smallest], a[i]);
        min_heapify(a, n, smallest);
    }
}

void minHeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i --)
    {
        min_heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i --)
    {
        swap(a[0], a[i]);
        min_heapify(a, i, 0);
    }
}

int main()
{
    int a[10] = {2, 5, 7, 3, 1, 4, 6, 9, 8, 11};
    minHeapSort(a, 10);
    for (int i = 0; i < 10; i ++)
    {
        cout << a[i] << endl;
    }
    system("pause");
    return 0;
}


