#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int met[n][n];
    memset(met, 0, sizeof(met));
    while(e--){
        int a,b;
        cin >> a >> b;
        met[a][b]=1;
        met[b][a]=1; // remove this when this a directed graph
    }
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            cout << met[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}