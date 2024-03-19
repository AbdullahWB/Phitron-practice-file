#include <bits/stdc++.h>
using namespace std;

int Knapsack(int n, int weight[], int value[], int w)
{
    if (n < 0 || w == 0)
        return 0;

    if (weight[n] <= w)
    {
        // 2 option
        // take or not
        int op1 = Knapsack(n - 1, weight, value, w - weight[n]) + value[n];
        int op2 = Knapsack(n - 1, weight, value, w);
        return max(op1, op2);
    }
    else
    {
        // one option
        // do not take
        int op2 = Knapsack(n - 1, weight, value, w);
        return (op2);
    }
}

int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int w;
    cin >> w;
    cout << Knapsack(n - 1, weight, value, w) << endl;
    return 0;
}