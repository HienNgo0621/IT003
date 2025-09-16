#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> input_vector(int n){
    vector<vector<int>> v(n, vector<int> (3));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < 3;  j ++){
            cin >> v[i][j];
        }
    }
    return v;
}

void Sort(vector<vector<int>> &v, int n){
    int max_x = v[0][1];
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < 3; j ++){
            
        }
    }
}

int main (){
    int n; cin >> n;
    vector<vector<int>> x = input_vector(n);

}