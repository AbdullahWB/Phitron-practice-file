#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Edge
{
public:
    ll u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const ll INF = 1e18;
ll dis[10000005];
vector<Edge> EdgeList;

int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    fill(dis, dis + n + 1, INF);
    ll s;
    cin >> s ;
    dis[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            ll u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool flag = false;
    for (Edge ed : EdgeList)
    {
        ll u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;
        if (dis[u] < INF && dis[u] + c < dis[v])
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        ll q;
        cin >> q;
        while (q--)
        {
            ll d;
            cin >> d;
            if (dis[d] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }
    return 0;
}