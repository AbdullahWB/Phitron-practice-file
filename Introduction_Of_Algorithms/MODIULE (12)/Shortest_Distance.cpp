#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll INF = 1e18;
vector<vector<long long>> adj;

void floydWarshall(int n)
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    adj.assign(n + 1, vector<long long>(n + 1, INF));
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    for (int i = 1; i <= n; ++i)
    {
        adj[i][i] = 0;
    }
    floydWarshall(n);
    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        if (adj[s][d] == INF)
            cout << -1 << endl;
        else
            cout << adj[s][d] << endl;
    }
    return 0;
}