#include <bits/stdc++.h>
using namespace std;

bool vis[20][20];
int level[20][20];
vector<int> v[100];
char a[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

// void bfs(int si, int sj)
// {
//     queue<pair<int, int>> q;
//     q.push({si, sj});
//     vis[si][sj] = true;
//     level[si][sj] = 0;
//     while (!q.empty())
//     {
//         pair<int, int> par = q.front();
//         q.pop();
//         cout << par.first << " " << par.second << endl;
//         for (int i = 0; i < 4; i++)
//         {
//             int ci = par.first + d[i].first;
//             int cj = par.second + d[i].second;
//             // cout << ci << " " << cj << endl;
//             if (valid(ci, cj) == true && vis[ci][cj] == false)
//             {
//                 q.push({si, sj});
//                 vis[ci][cj] = true;
//                 level[ci][cj] = level[par.first][par.second] + 1;
//             }
//         }
//     }
// }

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1; // Update level
            }
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
    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si, sj);
    cout << level[0][3] << " ";
    return 0;
}