#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string s="Hello, world!";
    // cout<< s.size()<<endl;
    // cout<< s.max_size()<<endl;
    // cout << s.capacity() << endl;
    // s.clear();
    // cout<< s.size()<<endl;
    // cout<< s<<endl;
    // if(s.empty()==true) cout<< "Empty string"<<endl;
    // else cout<< "Not Empty string"<<endl;

    string s;
    cin >> s;
    s.resize(5);
    s.resize(8,'x');
    cout<< s.size()<<endl;
    cout<< s<<endl;

    return 0;
}