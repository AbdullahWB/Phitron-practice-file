#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    int roll;
    int cla;
    double gpa;
    student(int roll, int cla, double gpa)
    {
        this->roll = roll;
        this->cla = cla;
        (*this).gpa = gpa;
    }
};

int main()
{
    student Abdullah(29, 34, 5.01);
    cout << Abdullah.roll << " " << Abdullah.cla << " " << Abdullah.gpa << endl;
    return 0;
}