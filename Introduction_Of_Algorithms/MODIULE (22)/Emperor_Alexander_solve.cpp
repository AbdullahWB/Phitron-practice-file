#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5 + 5;
ll parent[N];
ll group_size[N];

class Edge
{
public:
    ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

void dsu_initialize(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

ll dsu_find(ll x)
{
    if (parent[x] == -1)
        return x;
    return parent[x] = dsu_find(parent[x]);
}

void dsu_union_by_size(ll leaderA, ll leaderB)
{
    if (group_size[leaderA] > group_size[leaderB])
    {
        group_size[leaderA] += group_size[leaderB];
        parent[leaderB] = leaderA;
    }
    else
    {
        group_size[leaderB] += group_size[leaderA];
        parent[leaderA] = leaderB;
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> edgeList;
    while (e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    dsu_initialize(n);
    sort(edgeList.begin(), edgeList.end(), cmp);
    ll cnt = 0;
    ll total = 0;
    for (Edge ed : edgeList)
    {
        ll leaderA = dsu_find(ed.u);
        ll leaderB = dsu_find(ed.v);
        ll cost = ed.w;
        if (leaderA == leaderB)
        {
            cnt++;
        }
        else
        {
            dsu_union_by_size(leaderA, leaderB);
            total += cost;
        }
    }

    ll separateNodes = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (parent[i] == -1)
            separateNodes++;
    }

    if (separateNodes > 1)
        cout << "Not Possible" << endl;
    else
        cout << cnt << " " << total << endl;

    return 0;
}
