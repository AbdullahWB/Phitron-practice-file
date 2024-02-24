#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char adj[N][N];
bool vis[N][N];
int level[N][N];
vector<int> v[N];
int n, m;

vector<pair<int, int>> dirs = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj, int ti, int tj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ci = par.first + dirs[i].first;
            int cj = par.second + dirs[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        int adj[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                adj[i][j];
            }
        }
        int si, sj, ti, tj;
        cin >> si >> sj;
        cin >> ti >> tj;
        memset(vis, false, sizeof(vis));
        memset(level, -1, sizeof(level));
        bfs(si, sj, ti, tj);

        cout << level[ti][tj] << endl;
    }

    return 0;
}