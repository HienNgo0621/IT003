#include<iostream>
#include<vector>
using namespace std;

struct Graph
{
    int n;
    vector<vector<int>> adj;

    void init(int vertices)
    {
        n = vertices;
        adj.resize(n);
    }

    void addEdge(int u, int v)
    {
    adj[u].push_back(v);
    adj[v].push_back(u);
    }

    void printAdjList()
    {
        for (int i = 0; i < n; i ++)
        {
            cout << i << ": ";
            for (int j : adj[i])
                cout << j << " ";
            cout << endl;
        }
    }

    int countIsolationVertices()
    {
        int cnt = 0;
        for (int i = 0; i < n; i ++)
        {
            if (adj[i].empty())
            {
                cnt ++;
            }
        }
        return cnt;
    }

};

int main()
{
    int n, m;
    cin >> n >> m;

    Graph g;
    g.init(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Danh sach ke:\n";
    g.printAdjList();

    cout << "\nSo dinh co lap: " << g.countIsolationVertices() << endl;

    return 0;
}

