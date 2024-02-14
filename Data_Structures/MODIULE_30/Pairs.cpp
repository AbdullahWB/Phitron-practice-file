#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> pr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> pr[i].first >> pr[i].second;
    }

    sort(pr.begin(), pr.end(), cmp);

    for (auto it = pr.begin(); it != pr.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}