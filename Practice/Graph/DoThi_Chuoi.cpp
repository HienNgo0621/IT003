#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Graph
{
    int n = 0;
    map<string, int> nameToIndex;
    vector<string> indexToName;
    vector<vector<int>> adj;

    int getIndex(const string &name)
    {
        if (nameToIndex.count(name)) return nameToIndex[name];
        nameToIndex[name] = n ++;
        indexToName.push_back(name);
        adj.push_back({});
        return nameToIndex[name];
    }

    void addAdj(string u, string v)
    {
        int a = getIndex(u);
        int b = getIndex(v);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void printVertices()
    {
        for (int i = 0; i < n; i ++)
        {
            cout << indexToName[i] << ": ";
            for (int j : adj[i])
            {
                cout << indexToName[j] << " ";
            }
            cout << endl;
        }
    }

    int countIsolatedAdj(vector<string> &a)
    {
        int cnt = 0;
        for (int i = 0; i < n; i ++)
        {
            if (adj[i].empty())
            {
                cnt ++;
                a.push_back(indexToName[i]);
            }
        }
        return cnt;
    }
};

int main()
{
    Graph g;
    int m; cin >>  m;
    cin.ignore();
    for (int i = 0; i < m; i ++)
    {
        string x, y;
        getline(cin, x);
        getline(cin, y);
        g.addAdj(x, y);
    }
    g.getIndex("Tien Giang");
    g.printVertices();
    vector<string> ch;
    cout << g.countIsolatedAdj(ch) << endl;
    for (string c : ch)
    {
        cout << c << endl;
    }

    return 0;
}


