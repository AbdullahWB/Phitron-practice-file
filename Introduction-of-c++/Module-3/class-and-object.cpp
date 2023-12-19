#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    char name[100];
    int roll;
    double cgpa;
};

int main()
{
    student a, b;
    cin.getline(a.name, 100);
    cin >> a.roll >> a.cgpa;
    getchar();
    cin.getline(b.name, 100);
    cin >> b.roll >> b.cgpa;

    cout << a.name << " " << a.roll << " " << a.cgpa << endl;
    cout << b.name << " " << b.roll << " " << b.cgpa << endl;

    return 0;
}