#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char a[N][N];
bool vis[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && !vis[x][y];
}

void dfs(int x, int y, int n, int m)
{
    vis[x][y] = true;
    for (auto &dir : d)
    {
        int ci = x + dir.first;
        int cj = y + dir.second;
        if (valid(ci, cj, n, m))
        {
            dfs(ci, cj, n, m);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int apr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j, n, m);
                apr++;
            }
        }
    }
    cout << apr << endl;

    return 0;
}