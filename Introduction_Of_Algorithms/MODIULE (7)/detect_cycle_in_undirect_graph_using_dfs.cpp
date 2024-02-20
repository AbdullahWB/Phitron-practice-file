#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
bool pathVis[N];
bool ans;
vector<int> ar[N];
int parArray[N];
int n, e;

void dfs(int parent)
{
    vis[parent] = true;
    pathVis[parent] = true;
    for (int child : ar[parent])
    {
        if (pathVis[child])
        {
            ans = true;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    pathVis[parent] = false;
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        // ar[b].push_back(a);
    }
    ans = false;
    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (ans)
        cout << "cycle have" << endl;
    else
        cout << "no cycle have" << endl;
    return 0;
}