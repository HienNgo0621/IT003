#include<iostream>
#include<vector>
using namespace std;

struct Point2D
{
    int x, y;

    friend istream& operator >> (istream& in, Point2D &a)
    {
        in >> a.x >> a.y;
        return in;
    }

    friend ostream& operator << (ostream& out, const Point2D &a)
    {
        out << a.x << " " << a.y;
        return out;
    }

};

void InsertionSort(vector<Point2D> &a, int n)
{
    for (int i = 1; i < n; i ++)
    {
        Point2D key = a[i];
        int j = i - 1;
        while (j >= 0 && (a[j].x > key.x) || (a[j].x == key.x && a[j].y < key.y))
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int n; cin >> n;
    vector<Point2D> v(n);
    for (int i = 0; i < n; i ++)
    {
        cin >> v[i];
    }
    InsertionSort(v, n);
    for (int i = 0; i < n; i ++)
    {
        cout << v[i] << "\n\n";
    }
    return 0;
}
