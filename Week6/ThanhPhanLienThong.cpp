#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s)
{
    visited[s] = true;

    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            dfs(adj, visited, i);
}

// Main DFS function that initializes the visited array
// and call DFSRec
int countConnectedComponents(vector<vector<int>> &adj, int n){
    vector<bool> visited(n, false);
    int count = 0;  
    for (int i = 0; i < adj.size(); i ++){
        if (visited[i]){
            dfs(adj, visited, i);
            count ++;   
        }
    }
    return count;
}

void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int t, k;
        cin >> t >> k;
        addEdge(adj, t, k);
    }

    int cnt = countConnectedComponents(adj, n);
    cout << cnt;

    system("pause");
    return 0;
}