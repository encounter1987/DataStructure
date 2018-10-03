#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int s, d, v;

    edge(int s, int d, int v) : s(s), d(d), v(v)
    {
    }

    bool operator<(const edge &ob)
    {
        return this->v < ob.v;
    }

    friend ostream &operator<<(ostream &out, const edge &ob);
};

ostream &operator<<(ostream &out, const edge &ob)
{
    out << ob.s << " " << ob.d << " " << ob.v << endl;

    return out;
}

typedef vector<edge> Graph;

bool addedtoMst(Graph &mst, edge e, int V)
{
    vector<bool> Visited(V + 1, false);
    Visited[e.s - 1] = true;

    for (int i = 0; i < V; ++i)
    {
    }
}

void primeMst(const Graph &g, int V)
{
    int v = 1;
    Graph mst;
    mst.push_back(g[0]);

    while (v < V)
    {
        if (addedtoMst(mst, g[v]), V)
            v++;
    }
}

int main()
{
    freopen("Input", "r", stdin);

    int v, e;
    cin >> v >> e;
    Graph g;

    for (int i = 0; i < e; ++i)
    {
        int s, d, v;
        cin >> s >> d >> v;
        g.push_back(edge(s, d, v));
    }

    std::sort(g.begin(), g.end());

    primeMst(g, v);

    return 0;
}