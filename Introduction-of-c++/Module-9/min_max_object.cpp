#include <bits/stdc++.h>
using namespace std;

class students
{
public:
    string name;
    int age;
    int marks;
};

int main()
{
    int n;
    cin >> n;
    students a[n];
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        getline(cin, a[i].name);
        cin >> a[i].age >> a[i].marks;
    }
    students mn;
    mn.marks = INT_MAX;
    students mx;
    mx.marks = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i].marks < mn.marks)
        {
            mn = a[i];
        }
        if (a[i].marks > mx.marks)
        {
            mx = a[i];
        }
    }
    cout << mn.name << " " << mn.age << " " << mn.marks << endl;
    cout << mx.name << " " << mx.age << " " << mx.marks << endl;
    return 0;
}