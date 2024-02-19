#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int ai, int aj, int bi, int bj)
{
    if (vis[bi][bj] == true)
        return;
    vis[ai][aj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = ai + d[i].first;
        int cj = aj + d[i].second;
        if (valid(ci, cj) == true && a[ci][cj] != '#' && vis[ci][cj] == false)
        {
            dfs(ci, cj, bi, bj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int ai = -1, aj = -1, bi = -1, bj = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            else if (a[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }

    dfs(ai, aj, bi, bj);

    if (vis[bi][bj])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}