#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

bool subSetSum(int n, int target)
{
    if (n == target)
        return true;
    if (n > target)
        return false;
    if (dp[n] != -1)
        return dp[n];
    ;

    bool op1 = subSetSum(n + 3, target);
    bool op2 = subSetSum(n * 2, target);

    return dp[n] = op1 || op2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = -1;
        }
        if (subSetSum(1, n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
