#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<string> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Số phần tử của nửa trái
    int n2 = right - mid;      // Số phần tử của nửa phải

    // Tạo hai vector con
    vector<string> LeftArr(n1), RightArr(n2);

    // Sao chép dữ liệu vào hai vector con
    for (int i = 0; i < n1; i++) {
        LeftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        RightArr[i] = arr[mid + 1 + i];
    }

    // Chỉ mục của LeftArr, RightArr và vị trí hiện tại trong arr
    int i = 0, j = 0, current = left;

    // Gộp hai vector con theo thứ tự từ điển (dictionary order)
    while (i < n1 && j < n2) {
        if (LeftArr[i] <= RightArr[j]) {
            arr[current++] = LeftArr[i++];
        } else {
            arr[current++] = RightArr[j++];
        }
    }

    // Nối phần còn lại của LeftArr nếu có
    while (i < n1) {
        arr[current++] = LeftArr[i++];
    }

    // Nối phần còn lại của RightArr nếu có
    while (j < n2) {
        arr[current++] = RightArr[j++];
    }
}

void MergeSort(vector<string> &arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Sắp xếp nửa trái
        MergeSort(arr, left, mid);

        // Sắp xếp nửa phải
        MergeSort(arr, mid + 1, right);

        // Gộp hai nửa đã sắp xếp
        Merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Nhập từng chuỗi vào vector
    }

    MergeSort(arr, 0, n - 1);

    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) cnt++;
    }
    cout << cnt;

    system("pause");
    return 0;
}
