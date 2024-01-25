#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 0, 0};
    // list<int>nl={10,20,30};
    // vector<int>v={10,20,30};
    // list<int>l;
    // l2.push_back(100);
    // l2.push_front(100);
    // l2.pop_back();
    // l2.pop_front();
    // l.insert(next(l.begin(),2),100);
    // l.erase(next(l.begin(),2));
    // l.insert(next(l.begin(),2),{100,200,300});
    // l.insert(next(l.begin(),2),nl.begin(),nl.end());
    // l.insert(next(l.begin(),2),v.begin(),v.end());
    // l.erase(next(l.begin(),2),next(l.begin(),5));
    // replace(l.begin(), l.end(), 0, 100);
    // l.assign(l2.begin(),l2.end());
    // for (int val : l)
    // {
    //     cout << val << endl;
    // }
    auto it=find(l.begin(),l.end(), 11);
    // cout<<*it<<endl;
    if(it==l.end()){
        cout<< "Not Found"<<endl;
    }else{
        cout<<"Found"<<endl;
    }
    return 0;
}