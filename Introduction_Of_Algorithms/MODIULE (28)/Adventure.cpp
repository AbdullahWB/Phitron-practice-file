#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];

int Knapsack(int n, int weight[], int value[], int w)
{
    if (n < 0 || w == 0)
        return 0;
    if (dp[n][w] == -1)
    {
        if (weight[n] <= w)
        {
            int op1 = Knapsack(n - 1, weight, value, w - weight[n]) + value[n];
            int op2 = Knapsack(n - 1, weight, value, w);
            dp[n][w] = max(op1, op2);
        }
        else
        {
            dp[n][w] = Knapsack(n - 1, weight, value, w);
        }
    }
    return dp[n][w];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int weight[n], value[n];
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> value[i];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << Knapsack(n - 1, weight, value, w) << endl;
    }
    return 0;
}