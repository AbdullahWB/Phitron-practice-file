#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
int level[1005];

void bfs(int src, int dst)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;
    // level[src] = 0;
    bool found = false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        // cout<<par<<endl;
        int par = p.first;
        int level = p.second;
        if (par == dst)
        {
            cout << level << " ";
            found = true;
        }
        for (int child : v[par])
        {
            if (!vis[child])
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    if (!found)
    {
        cout << -1 << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); 
    }
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(src, 10);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Index: " << i << " "
    //          << "Level: " << level[i] << endl;
    // }

    return 0;
}