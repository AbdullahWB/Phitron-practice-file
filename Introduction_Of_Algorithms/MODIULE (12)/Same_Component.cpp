#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char adj[N][N];
bool vis[N][N];

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int a, int b, int n, int m)
{
    return a >= 0 && a < n && b >= 0 && b < m && adj[a][b] == '.' && !vis[a][b];
};

void dfs(int a, int b, int n, int m)
{
    vis[a][b] = true;
    for (auto &dir : dirs)
    {
        int ca = a + dir.first;
        int cb = b + dir.second;
        if (valid(ca, cb, n, m))
        {
            dfs(ca, cb, n, m);
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adj[i][j];
        }
    }
    int cx, cy, ci, cj;
    cin >> cx >> cy >> ci >> cj;
    memset(vis, false, sizeof(vis));
    dfs(cx, cy, n, m);

    if (vis[ci][cj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}