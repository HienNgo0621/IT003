#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0;  j < 2; j ++){
            cin >> adj[i][j];
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < m; j++)
        {
            if (i == adj[j][0] || i == adj[j][1])
            {
                found = true;
            }
        }
        if (!found)
            cnt ++;
    }
    cout << cnt;

    system("pause");
    return 0;
}