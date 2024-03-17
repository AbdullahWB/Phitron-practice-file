#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    int ans = fibonacci(n - 1) + fibonacci(n - 2);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int fibonacciCnt = fibonacci(n);
    cout << fibonacciCnt << endl;
    return 0;
}