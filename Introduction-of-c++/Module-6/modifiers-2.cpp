#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    cout << a << endl;
    a="Hello, world!";
    cout << a << endl;
    a.assign("Hello world");
    cout << a << endl;
    a.erase(4,1);
    cout << a << endl;
    a.replace(4,0,"o");
    cout << a << endl;
    a.insert(5," Abdullah"); 
    cout << a << endl;
    return 0;
}