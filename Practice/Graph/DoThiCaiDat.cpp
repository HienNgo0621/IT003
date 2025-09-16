#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<string> nodes;
vector<pair<string, string>> edges;
unordered_map<string, int> nodeIndex;
vector<vector<int>> matrix;
vector<int> weights;

int findIndex(const string &a){
    for (int i = 0; i < nodes.size(); i ++){
        if (a == nodes[i]) return 1;
    }
    return -1;
}

void Input(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        string x, y; int w;
        cin >> x >> y >> w;
        if (findIndex(x) == -1){
            nodeIndex[x] = nodes.size();
            nodes.push_back(x);
        }
        if (findIndex(y) == -1){
            nodeIndex[y] = nodes.size();
            nodes.push_back(y);
        }       

        edges.push_back({x,y});
        weights.push_back(w);
    }

    int num = nodes.size();
    matrix = vector<vector<int>> (num, vector<int> (num,0));

    for (int i = 0; i < edges.size(); i ++){
        int from = nodeIndex[edges[i].first];
        int to = nodeIndex[edges[i].second];
        matrix[from][to] = weights[i];
        matrix[to][from] = weights[i];
    }
}

bool haiCanhKe(const string &a, const string &b){
    if (nodeIndex.find(a) == nodeIndex.end() || nodeIndex.find(b) == nodeIndex.end()){
        return false;
    }
    int i = nodeIndex[a];
    int j = nodeIndex[b];
    return matrix[i][j] != 0 || matrix[j][i] != 0;
}

void lietKeDinhKe(const string &a){
    if (nodeIndex.find(a) == nodeIndex.end()){
        cout << "Khong ton tai dinh\n";
        return;
    }
    int k = nodeIndex[a];
    for (int i = 0; i < matrix.size(); i ++){
        if (matrix[k][i] != 0)
            cout << nodes[i] << endl;
    }
}

int main() {
    Input(); // Nhập số cạnh và danh sách cạnh có trọng số

    cout << "\n=== Ma tran ke ===\n";
    for (int i = 0; i < nodes.size(); ++i) {
        for (int j = 0; j < nodes.size(); ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n=== Kiem tra ke nhau ===\n";
    string u, v;
    cout << "Nhap 2 dinh u va v: ";
    cin >> u >> v;
    if (haiCanhKe(u, v))
        cout << u << " ke voi " << v << endl;
    else
        cout << u << " KHONG ke voi " << v << endl;

    cout << "\n=== Liet ke cac dinh ke ===\n";
    string s;
    cout << "Nhap dinh can liet ke: ";
    cin >> s;
    lietKeDinhKe(s);
    system("pause");
    return 0;
}