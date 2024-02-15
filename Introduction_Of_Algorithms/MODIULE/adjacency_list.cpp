#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin >> n >> e;
    vector<int>mat[n];
    while (n--){
        int a,b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a); // remove this when this a directed graph
    }
    for(int val:mat[0]){
        cout << val << " ";
    }
    return 0;
}