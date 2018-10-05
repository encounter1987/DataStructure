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

int find(vector<int> &Parent, int key)
{
    if (Parent[key] != key)
    {
        Parent[key] = Parent[Parent[key]];
        find(Parent, Parent[key]);
    }

    return Parent[key];
}

void krushkalMst(const Graph &g, int V)
{
    vector<int> Height(V, 1);
    vector<int> Parent(V);

    vector<edge> res;

    for (int i = 0; i < V; ++i)
        Parent[i] = i;

    int e = 0;
    while (res.size() < V - 1)
    {
        int x = find(Parent, g[e].s);
        int y = find(Parent, g[e].d);

        if (x != y)
        {
            res.push_back(g[e]);

            if (Height[x] > Height[y])
            {
                Parent[y] = x;
            }
            else if (Height[x] < Height[y])
            {
                Parent[x] = y;
            }
            else
            {
                Parent[y] = x;
                Height[x]++;
            }
        }

        e++;
    }

    for (int i = 0; i < res.size(); ++i)
        cout << res[i];
#if 0
    cout << endl;
    for (int i = 0; i < Parent.size(); ++i)
        cout << Parent[i] << " ";
    cout << endl;
    for (int i = 0; i < Height.size(); ++i)
        cout << Height[i] << " ";

    cout << endl;
#endif
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

#if 0
    for (int i = 0; i < e; ++i)
    {
        cout << g[i];
    }
    cout << endl;
#endif

    krushkalMst(g, v);

    return 0;
}