#include <iostream>
#include <vector>
#include <string>

struct Product {
    std::string code;
    int count;
};

void mergeStrings(std::vector<std::string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].length() < R[j].length() || 
           (L[i].length() == R[j].length() && L[i] < R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void SortStrings(std::vector<std::string>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    SortStrings(arr, left, mid);
    SortStrings(arr, mid + 1, right);
    mergeStrings(arr, left, mid, right);
}

void mergeProducts(std::vector<Product>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Product> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].count > R[j].count || 
           (L[i].count == R[j].count && 
           (L[i].code.length() < R[j].code.length() || 
           (L[i].code.length() == R[j].code.length() && L[i].code < R[j].code)))) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void SortProducts(std::vector<Product>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    SortProducts(arr, left, mid);
    SortProducts(arr, mid + 1, right);
    mergeProducts(arr, left, mid, right);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<std::string> codes(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> codes[i];
    }

    SortStrings(codes, 0, N-1);

    std::vector<Product> products;
    if (!codes.empty()) {
        std::string current = codes[0];
        int count = 1;
        
        for (int i = 1; i < N; i++) {
            if (codes[i] == current) {
                count++;
            } else {
                products.push_back({current, count});
                current = codes[i];
                count = 1;
            }
        }
        products.push_back({current, count});
    }

    SortProducts(products, 0, products.size()-1);

    for (const auto& p : products) {
        std::cout << p.code << " " << p.count << "\n";
    }
    system("pause");
    return 0;
}