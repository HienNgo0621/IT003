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
    sort(res.begin(), res.end());
    if (res.size() <= 1)
    {
        cout << "KHONG";
    }
    else
    {
        for (int i = 1; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }

    system("pause");
    return 0;
}