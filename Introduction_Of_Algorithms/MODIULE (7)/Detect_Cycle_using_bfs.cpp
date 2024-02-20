#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> ad[N];
int parArray[N];
bool ans;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        vis[parent] = true;
        // cout << parent << endl;
        for (int child : ad[parent])
        {
            if (vis[child] && parArray[parent] != child)
            {
                ans = true;
            }
            if (!vis[child])
            {
                vis[child] = true;
                parArray[child] = parent;
                q.push(child);
            }
        }
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
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parArray, -1, sizeof(parArray));
    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    if (ans == true)
        cout << "cycle have" << endl;
    else
        cout << "not cycle have" << endl;
    return 0;
}