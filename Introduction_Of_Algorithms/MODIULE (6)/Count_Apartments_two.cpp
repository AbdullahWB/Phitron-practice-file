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

int dfs(int x, int y, int n, int m)
{
    vis[x][y] = true;
    int cnt = 1;
    for (auto &dir : d)
    {
        int ci = x + dir.first;
        int cj = y + dir.second;
        if (valid(ci, cj, n, m))
        {
            cnt += dfs(ci, cj, n, m);
        }
    }
    return cnt;
};

int main()
{
    int n, m;
    cin >> n >> m;
    bool allWall = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != '#')
            {
                allWall = false;
            }
        }
    }
    if (allWall)
    {
        cout << 0 << endl;
        return 0;
    }
    memset(vis, false, sizeof(vis));
    vector<int> aprCount;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.' && !vis[i][j])
            {
                int roomCount = dfs(i, j, n, m);
                aprCount.push_back(roomCount);
            }
        }
    }

    sort(aprCount.begin(), aprCount.end());

    for (int count : aprCount)
    {
        cout << count << " ";
    }

    return 0;
}