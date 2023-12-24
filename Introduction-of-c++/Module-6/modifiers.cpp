#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;

    a += b;
    cout << a << endl;
    a.append(b);
    cout << a << endl;
    a="Hello, world!";
    cout << a << endl;
    a=a+b;
    cout << a << endl;
    a.push_back('x');
    cout << a << endl;
    a.pop_back();
    cout << a << endl;
    a=a+'A';
    cout << a << endl;

    return 0;
}