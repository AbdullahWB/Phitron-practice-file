#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--){
        string s,x;
        cin >> s >> x;
        size_t find = s.find(x);
        while (find != string::npos)
        {
            s.replace(find, x.length(), "#");
            find=s.find(x,find+1);
        }
        cout << s << endl;
    }
    return 0;
}