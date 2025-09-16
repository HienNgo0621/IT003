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

    void addAdj(char u, char v)
    {
        int a = u - 'A';
        int b = v - 'A';
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void printVertices()
    {
        for (int i = 0; i < n; i ++)
        {
            cout << char('A' + i) << ": ";
            for (int j : adj[i])
            {
                cout << char('A' + j) << " ";
            }
            cout << endl;
        }
    }

    int countIsolatedAdj(vector<char> &a)
    {
        int cnt = 0;
        for (int i = 0; i < n; i ++)
        {
            if (adj[i].empty())
            {
                cnt ++;
                a.push_back(char('A' + i));
            }
        }
        return cnt;
    }
};

int main()
{
    Graph g;
    int n, m; cin >> n >> m;
    g.init(n);
    for (int i = 0; i < m; i ++)
    {
        char x, y;
        cin >> x >> y;
        g.addAdj(x, y);
    }
    g.printVertices();
    vector<char> ch;
    cout << g.countIsolatedAdj(ch) << endl;
    for (char c : ch)
    {
        cout << c << endl;
    }
    return 0;
}


