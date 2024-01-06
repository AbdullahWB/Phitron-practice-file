#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v={10,20,30,40,50,60};
    v.pop_back();
    v.pop_back();
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    // vector<int> y={1,2,3,4};
    // y=v; //O(n)
    // for(int i=0;i<y.size();i++){
    //     cout << y[i] << " ";
    // }
    return 0;
}