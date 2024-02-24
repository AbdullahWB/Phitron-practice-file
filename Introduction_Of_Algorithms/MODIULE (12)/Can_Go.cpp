#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 1e6 + 5;
vector<pair<ll, ll>> v[N];
ll dis[N];

class cmp
{
public:
    bool operator()(pair<ll,ll> a, pair<ll,ll> b)
    {
        return a.second < b.second;
    }
};

void dijktra(int src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<ll, ll> paren = pq.top();
        pq.pop();
        ll node = paren.first;
        ll cost = paren.second;
        for (auto &child : v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        // v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    ll s;
    cin >> s;
    dijktra(s);
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        if (dis[x] <= y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}