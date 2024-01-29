#include <bits/stdc++.h>
using namespace std;

void print(const list<int> &MyList){
    cout<<"L -> ";
    for(const auto &val : MyList){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<"R -> ";
    for(auto it=MyList.rbegin(); it!=MyList.rend(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    int q;
    cin >> q;

    list<int>MyList;

    while(q--){
        int x,v;
        cin>>x>>v;

        if(x==0){
            MyList.push_front(v);
        }else if(x==1){
            MyList.push_back(v);
        }else  if (x == 2 && v >= 0 && v < static_cast<int>(MyList.size())){
            MyList.erase(next(MyList.begin(),v));
        }
        print(MyList);
    }

    return 0;
}