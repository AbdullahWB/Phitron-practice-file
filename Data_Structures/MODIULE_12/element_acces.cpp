#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int>l={10,20,30};
    cout<<l.front()<<" "<<l.back()<<endl;
    cout<< *next(l.begin(),1)<<endl;
    return 0;
}