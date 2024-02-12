#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    while (true)
    {
        int c;
        cin >> c;
        if (c == 0)
        {
            int x;
            cin >> x;
            pq.push(x); //N Log(n);
        }
        else if (c == 1)
        {
            pq.pop(); //N Log(n);
        }
        else if (c == 2)
        {
            cout << "Top Value: " << pq.top() << endl; //O(1);
        }
        else
        {
            break;
        }
    }
    return 0;
}