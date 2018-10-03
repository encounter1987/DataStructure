#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Graph;

int minCostIndex(const vector<bool> &Included, const vector<int> &Cost)
{
    int min = INT32_MAX;
    int index;

    for (int i = 0; i < Cost.size(); ++i)
    {
        if (!Included[i] && min > Cost[i])
        {
            min = Cost[i];
            index = i;
        }
    }

    return index;
}

void primeMst(const Graph &g, int V)
{
    vector<bool> Included(V, false);
    vector<int> Cost(V, INT32_MAX);
    vector<int> Node2(V, -1); //Node1 is the respective index itself

    Cost[0] = 0;

    for (int e = 0; e < V - 1; ++e)
    {
        int parent = minCostIndex(Included, Cost);
        Included[parent] = true;

        for (int i = 0; i < V; ++i)
        {
            if (!Included[i] &&
                parent != i &&
                g[parent][i] != 0 &&
                Cost[i] > g[parent][i])
            {
                Node2[i] = parent;
                Cost[i] = g[parent][i];
            }
        }
    }

    cout << "MST:\n";

    for (int i = 1; i < V; ++i)
    {
        printf("%d - %d \t%d \n", Node2[i], i, g[Node2[i]][i]);
    }
}

int main()
{
    freopen("Input", "r", stdin);

    int v, e;
    cin >> v >> e;
    Graph g(v, vector<int>(v, 0));

    for (int i = 0; i < e; ++i)
    {
        int s, d, v;
        cin >> s >> d >> v;
        g[s][d] = g[d][s] = v;
    }

    primeMst(g, v);

    return 0;
}