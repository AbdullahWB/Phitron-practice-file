#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool subSetSum(ll initial, ll n) {
    if (initial == n) return true;
    if (initial > n) return false;

    bool op1 = subSetSum(initial + 3, n);
    bool op2 = subSetSum(initial * 2, n);

    return op1 || op2;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (subSetSum(1, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
