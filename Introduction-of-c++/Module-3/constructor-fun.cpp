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

student *fun()
{
    student *karim=new student(29, 34, 5.01);
    // student *p = &Abdullah;
    return karim;
};

int main()
{
    student *ans = fun();
    cout << ans->cla << " " << ans->roll << " " << ans->gpa << endl;
    delete ans;
    cout << ans->cla << " " << ans->roll << " " << ans->gpa << endl;
    return 0;
}