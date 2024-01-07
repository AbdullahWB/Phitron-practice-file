#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v={1,2,2,4,2,6,2,2,8,2};
    replace(v.begin(),v.end()-1,2,100);
    cout << v.size() << endl;
    for(int s:v){
        cout << s << " ";
    }
    return 0;
}