#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> input_vector(int n, int m){
    vector<vector<int>> v(n, vector<int> (m));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> v[i][j];
        }
    }
    return v;
}

int Min_Enrichement(const vector<vector<int>> &v, int n, int m){
    int min_sum = INT_MAX;
    for (int i = 0; i < n - 2; i ++){
        for (int j = 0; j < m - 2; j ++){
            int sum = v[i][j] + v[i][j + 1] + v[i][j + 2]
            + v[i + 1][j] + v[i + 1][j + 1] + v[i + 1][j + 2]
            + v[i + 2][j] + v[i + 2][j + 1] + v[i + 2][j + 2];
            min_sum = min(min_sum, sum);
        }
    }
    return min_sum;
}

int main (){
    int n ,m;
    cin >> n >> m;
    vector<vector<int>> v = input_vector(n, m);
    cout << Min_Enrichement(v, n, m) << endl;
    system("pause");
    return 0;
}