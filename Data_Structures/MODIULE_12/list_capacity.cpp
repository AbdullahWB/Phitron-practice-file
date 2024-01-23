#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int>l={10,20,30};
    // cout<<l.max_size()<<endl;
    // l.clear();
    l.resize(2);
    l.resize(5);
    cout<<l.size()<<endl;
    for(int val:l){
        cout<<val<<endl;
    }
    return 0;
}