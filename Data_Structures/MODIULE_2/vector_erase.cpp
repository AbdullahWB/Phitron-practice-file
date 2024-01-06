#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v={1,2,3,4,5,6,7};
    // v.erase(v.begin()+3);
    v.erase(v.begin()+3,v.end()-1);
    for(int s: v){
        cout << s << " ";
    }
    return 0;
}