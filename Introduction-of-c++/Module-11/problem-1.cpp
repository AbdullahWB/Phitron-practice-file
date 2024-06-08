#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s, x;
        cin >> s >> x;
        int pos;
        while ((pos = s.find(x)) != -1) {
            s.replace(pos, x.length(), "#");
        }
        cout << s << endl;
    }
    
    return 0;
}