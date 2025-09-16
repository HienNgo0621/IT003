#include<iostream>
#include<vector>
using namespace std;

struct Point3D
{
    int x, y, z;

    friend istream& operator >> (istream& in, Point3D &a)
    {
        in >> a.x >> a.y >> a.z;
        return in;
    }

    friend ostream& operator << (ostream& out, const Point3D &a)
    {
        out << a.x << " " << a.y << " " << a.z;
        return out;
    }

};

bool compare(Point3D a, Point3D b)
{
    if (a.x != b.x) return a.x > b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z > b.z;
}

void InsertionSort(vector<Point3D> &a, int n)
{
    for (int i = 1; i < n; i ++)
    {
        Point3D key = a[i];
        int j = i - 1;
        while (j >= 0 && (compare(a[j], key)))
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
    vector<Point3D> v(n);
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
