#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v={1,2,3,4,5,6,7,3};
    // vector<int>::iterator it;
    auto it=find(v.begin(),v.end(),3);
    // cout<< *it<<endl;
    if(it==v.end()) cout<< "Not Found"<<endl;
    else cout<<"Found"<<endl;
    return 0;
}