#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
bool ans;
vector<int> ar[N];
int parArray[N];
int n, e;

void dfs(int parent)
{
    vis[parent] = true;
    // cout << parent << endl;
    for (int child : ar[parent])
    {
        if (vis[child] && parArray[parent] != child)
        {
            ans = true;
        }
        if (!vis[child])
        {
            // vis[child] = true;
            parArray[child] = parent;
            dfs(child);
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parArray, -1, sizeof(parArray));
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
        cout << "have no cycle" << endl;
    return 0;
}