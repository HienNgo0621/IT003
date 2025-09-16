#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<limits>
using namespace std;

typedef pair<string, string> vertex;

struct cGraph
{
    vector<vector<vertex>> listBorderPairs;

    unordered_map<vertex, int> order;

    bool isAdjVertices(const vertex &v1, string country)
    {
        if (order.find(v1) != order.end())
        {
            for (vertex v : listBorderPairs[order[v1]])
            {
                if (v.first == country)
                    return true;
            }
        }
        return false;
    }
};

string MostBordered_Country(const cGraph &g)
{
    if (g.listBorderPairs.size() == 0){
        return "This country has no neighboring countries.";
    }
    int max = numeric_limits<int>::min();
    string result;
    for (auto [v, n] : g.order)
    {
        if (g.listBorderPairs[n].size() > max)
        {
            max = n;
            result = v.first;
        }
    }
    return result;
}