#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp.insert({"Mohammad Abdullah", 369});
    mp.insert({"Sakibal Hasan", 69});
    mp.insert({"Musfikur Rahim", 33});
    mp["Masum Rana"]=75;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first  << " ";
        cout << it->second << endl;
    }
    cout<<mp["Mohammad Abdullah"]<<endl;
    if(mp.count("Mohammad Abdullah")){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}