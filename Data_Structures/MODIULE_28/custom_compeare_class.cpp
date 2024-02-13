#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int mark;
    Student(string name, int roll, int mark)
    {
        this->mark = mark;
        this->roll = roll;
        this->name = name;
    }
};

class cpm
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.mark <= b.mark)
            return true;
        else
            return false;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cpm> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, mark;
        cin >> name >> roll >> mark;
        Student obj(name, roll, mark);
        pq.push(obj);
    }

    while (!pq.empty())
    {
        cout << "Name: " << pq.top().name << endl
             << "Roll: " << pq.top().roll << endl
             << "Mark: " << pq.top().mark << endl
             << endl
             << endl;

        pq.pop();
    }

    return 0;
}