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
        if (a.mark == b.mark)
            return a.roll > b.roll;
        return a.mark < b.mark;
    }
};

int main()
{
    priority_queue<Student, vector<Student>, cpm> pq;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string name;
        int roll, mark;
        cin >> name >> roll >> mark;
        Student obj(name, roll, mark);
        pq.push(obj);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            string name;
            int roll, mark;
            cin >> name >> roll >> mark;
            Student obj(name, roll, mark);
            pq.push(obj);
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
        }
        else if (n == 1)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
            }
        }
        else if (n == 2)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                pq.pop();
                if (!pq.empty())
                {
                    cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
                }
                else
                {
                    cout << "Empty" << endl;
                }
            }
        }
    }
    return 0;
}