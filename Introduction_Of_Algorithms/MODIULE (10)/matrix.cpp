#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n>>m;   
    // int m[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<i<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}