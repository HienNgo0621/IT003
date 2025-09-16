#include<iostream>
#include<vector>
using namespace std;

int compareVectors(const vector<double> &a, const vector<double> &b) {
    for (int i = 0; i < 3; i++) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    return 0; 
}

int binarySearch(const vector<vector<double>> &a, int n, int &cnt, const vector<double> &b){
    int start = 0, end = n - 1;
    while (start <= end){
        int mid = (start + end) / 2;
        cnt ++;
        int cmp = compareVectors(b, a[mid]);
        if (cmp == 0) return 1;
        else if (cmp < 0) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<vector<double>> a(n, vector<double> (3));

    for (int i = 0; i < n; i ++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int m; cin >> m;
    vector<vector<double>> b(m, vector<double> (3));
    for (int i = 0; i < m; i ++){
        cin >> b[i][0] >> b[i][1] >> b[i][2];
    }

    for (int i = 0; i < m; i ++){
        int cnt = 0;
        if (binarySearch(a, n, cnt, b[i]) == -1) cout << "KHONG";
        else cout << cnt;
        cout << "\n";
    }

    system("pause");
    return 0;
}