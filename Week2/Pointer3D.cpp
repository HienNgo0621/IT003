#include<iostream>
#include<vector>
using namespace std;

struct Point{
    int x, y, z;
};

void input(vector<Point> &v, int n){
    for (int i = 0; i < n; i ++){
        cin >> v[i].x >> v[i].y >> v[i].z;
    }
}

void output(const vector<Point> &v, int n){
    for (int i = 0; i < n; i ++){
        cout << v[i].x << " " << v[i].y << " " << v[i].z << "\n\n";
    }
}

void Swap(Point &a, Point &b){
    Point temp = a;
    a = b;
    b = temp;
}

bool compare(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;  // x tăng dần
    else if (a.y != b.y) return a.y > b.y;  // y giảm dần
    return a.z < b.z;
}

// Hàm Partition cho QuickSort
int Partition(vector<Point> &v, int low, int high) {
    Point pivot = v[high];  // Chọn phần tử cuối làm chốt
    int i = low - 1;        // Vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (compare(v[j], pivot)) {  // neu v[j] nho hon pivot thi doi cho
            i++;
            Swap(v[i], v[j]);
        }
    }
    Swap(v[i + 1], v[high]);  // dua pivot ve dung vi tri
    return i + 1;
}

// Ham QuickSort de quy
void QuickSort(vector<Point> &v, int low, int high) {
    if (low < high) {
        int pi = Partition(v, low, high);
        QuickSort(v, low, pi - 1);
        QuickSort(v, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Point> v(n);

    input(v, n);
    QuickSort(v, 0, n - 1);
    output(v, n);

    system("pause");
    return 0;
}
