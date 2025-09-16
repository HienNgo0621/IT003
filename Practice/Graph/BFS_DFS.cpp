#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define MAX 100

vector<int> adj[MAX];
bool visited[MAX];

void BFS(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()){
        int u = q.front(); q.pop();
        cout << u << " ";
        for (auto v : adj[u]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void DFS(int start){
    stack<int> st;
    st.push(start);
    visited[start] = true;
    while (!st.empty()){
        int u = st.top(); st.pop();
        cout << u << " ";

        for (int i = adj[u].size() - 1; i >= 0; i --){
            int v = adj[u][i];
            if (!visited[v]){
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

void dfsRecursion(int u){
    visited[u] = true;
    cout << u << " ";
    for (auto v : adj[u]){
        if (!visited[v]){
            dfsRecursion(v);
        }
    }
}

void resetVisited(){
    for (int i = 0; i < MAX; i ++) visited[i] = false;
}


int main() {
    int n = 6; // số đỉnh
    // Cài đặt danh sách kề cho đồ thị ví dụ
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {2};
    adj[5] = {3};

    cout << "BFS tu dinh 0: ";
    BFS(0);

    resetVisited();

    cout << "\nDFS tu dinh 0: ";
    dfsRecursion(0);
    system("pause");
    return 0;
}
