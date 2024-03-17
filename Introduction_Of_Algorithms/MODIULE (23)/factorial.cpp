#include <bits/stdc++.h>
using namespace std;

//O(N);
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int smallFactorial = fact(n - 1);
    return smallFactorial * n;
}

int main()
{
    int n;
    cin >> n;
    int count = fact(n);
    cout << count << endl;

    //O(N);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }
    cout << ans << endl;

    return 0;
}