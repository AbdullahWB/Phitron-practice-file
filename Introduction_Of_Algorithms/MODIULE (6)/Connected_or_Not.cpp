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
        // met[b][a]=1; 
    }
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if(met[x][y] || x==y){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}