#include <bits/stdc++.h>
using namespace std;

int main()
{
    // list<int>l;
    // list<int>l(10,5);
    // cout<<l.front()<<endl;
    // list<int>l2={1,2,3,4,5};
    // list<int>l(l2);
    // int a[5]={10,20,30,40,50};
    // list<int>l(a,a+5);  
    vector<int>v={10,20,30,40,50};
    list<int>l(v.begin(),v.end());


    // for(auto it=l.begin(); it != l.end(); it++){
    //     cout<<*it<<endl;
    // }


    for(int val:l){
        cout<<val<<endl;
    }

    return 0;
}