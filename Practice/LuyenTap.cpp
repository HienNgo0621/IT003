#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<string> qgia;
vector<pair<string,string>> canh;
vector<vector<int>> matrix;
unordered_map<string,int> qgiaIdx;
vector<string> col = {"do", "cam", "vang", "luc", "lam", "cham", "tim"};
unordered_map<int,string> mauQgia;

void input(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++){
        string a;
        getline(cin >> ws, a);
        qgiaIdx[a] = qgia.size();
        qgia.push_back(a);
    }

    for (int i = 0; i < m; i ++){
        string x, y;
        getline(cin >> ws, x);
        getline(cin >> ws, y);
        if (qgiaIdx.find(x) != qgiaIdx.end() && qgiaIdx.find(y) != qgiaIdx.end()) canh.push_back({x,y});
    }

    int num = qgia.size();
    matrix = vector<vector<int>> (num, vector<int> (num, 0));
    for (int i = 0; i < canh.size(); i ++){
        int from = qgiaIdx[canh[i].first];
        int to = qgiaIdx[canh[i].second];
        matrix[from][to] = 1;
        matrix[to][from] = 1;
    }
}

int keNhau(const string &a, const string &b){
    int i = qgiaIdx[a];
    int j = qgiaIdx[b];
    return matrix[i][j] != 0 || matrix[j][i] != 0;
}

void listDinhKe(const string &a){
    for (int i = 0; i < qgia.size(); i++){
        if (keNhau(a, qgia[i])) cout << qgia[i] << endl;
    }
}

void toMau(){
    for (int i = 0; i < qgia.size(); i ++){
        unordered_map<string, bool> daDung;
        for (int j = 0; j < qgia.size(); j ++){
            if (matrix[i][j] != 0 && mauQgia.count(j)){
                daDung[mauQgia[j]] = true;
            }
        }
        
        for (string c : col){
            if (!daDung[c]){
                mauQgia[i] = c;
                break;
            }
        }
    }
}

void maxBienGioi(){
    unordered_map<int, int> maxBien;
    for(int i = 0; i < qgia.size();  i++){
        for (int j = 0; j < qgia.size(); j ++){
            if (matrix[i][j]) maxBien[i] ++;
        }
    }

    int max = 0;
    for (int i = 0; i < qgia.size(); i ++){
        if (max < maxBien[i]) max = maxBien[i];
    }
    for (int i = 0; i < qgia.size(); i ++){
        if (max == maxBien[i]) cout << qgia[i] << "\t";
    }
}

int main() {
    input();

    cout << "\n=== Danh sách quốc gia và màu tô ===\n";
    toMau();
    for (int i = 0; i < qgia.size(); i++) {
        cout << qgia[i] << ": " << mauQgia[i] << endl;
    }

    cout << "\n=== Quoc gia co nhieu bien gioi nhat ===\n";
    maxBienGioi();
    system("pause");
    return 0;
}
