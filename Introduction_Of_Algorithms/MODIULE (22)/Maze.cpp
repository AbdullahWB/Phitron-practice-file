#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
bool vis[N][N];
int dis[N][N];
char a[N][N];
int n, m;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int ci, int cj)
{
    return ci >= 0 && cj >= 0 && ci < n && cj < n;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && a[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[par.first][par.second] + 1;
            }
        }
    }
}

int main()
{
    while (cin >> n)
    {
        cin >> m;
        int si = -1, sj = -1; 
        int di = -1, dj=-1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'R')
                {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == 'D')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);

        int ci = di, cj = dj;
        while (ci != si || cj != sj)
        {
            for (int i = 0; i < 4; i++)
            {
                int pi = ci - d[i].first;
                int pj = cj - d[i].second;
                if (valid(pi, pj) && dis[ci][cj] == dis[pi][pj] + 1)
                {
                    ci = pi;
                    cj = pj;
                    if (a[ci][cj] != 'R')
                        a[ci][cj] = 'X';
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << "";
            }
            cout << endl;
        }
    }
    return 0;
}