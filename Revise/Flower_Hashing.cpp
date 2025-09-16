#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> freq;
    vector<int> result;
    for (int i = 0; i < A.size(); i ++)
    {
        freq[A[i]]++;
    }

    for (auto it : freq)
    {
        result.push_back(it.first);
        if (result.size() == K) break;
    }

    if (result.size() < K)
    {
        for (auto it : freq)
        {
            int already = count(result.begin(), result.end(), it.first);
            int remain = it.second - already;

            while (remain > 0 && result.size() < K)
            {
                result.push_back(it.first);
                remain --;
            }
            if (result.size() == K) break;
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
