#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{
    visited[s] = true;
    res.push_back(s);
    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            dfs(adj, visited, i, res);
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
    vector<int> res;
    vector<bool> visited(n, false);

    dfs(adj, visited, 0, res);
    
    for (int i = 1; i < n; i ++){
        bool found = false;
        for (int j = 0; j < res.size(); j ++){
            if (i == res[j]) found = true;
        }
        if (found) cout << "CO" << endl;
        else cout << "KHONG" << endl;
    }

    system("pause");
    return 0;
}