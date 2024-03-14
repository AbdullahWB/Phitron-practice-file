#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char a[N][N];
bool vis[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.';
}

int dfs(int x, int y, int n, int m)
{
    vis[x][y] = true;
    int cnt = 1;
    for (auto &child : d)
    {
        int ci = x + child.first;
        int cj = y + child.second;
        if (valid(ci, cj, n, m) && !vis[ci][cj])
        {
            cnt += dfs(ci, cj, n, m);
        }
    }
    return cnt;
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
    int min_area = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                int area = dfs(i, j, n, m);
                min_area = min(min_area, area);
            }
        }
    }
    if (min_area == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_area << endl;
    }
    return 0;
}
