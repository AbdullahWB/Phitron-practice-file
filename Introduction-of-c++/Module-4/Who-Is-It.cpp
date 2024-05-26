#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    int id;
    char name[100];
    char section[2];
    int mark;
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        student sakib, rakib, akib;
        cin >> sakib.id >> sakib.name >> sakib.section >> sakib.mark;
        cin >> rakib.id >> rakib.name >> rakib.section >> rakib.mark;
        cin >> akib.id >> akib.name >> akib.section >> akib.mark;

        if (sakib.mark >= rakib.mark && sakib.mark >= akib.mark)
        {
            cout << sakib.id << " " << sakib.name << " " << sakib.section << " " << sakib.mark << endl;
        }
        else if (rakib.mark >= sakib.mark && rakib.mark >= akib.mark)
        {
            cout << rakib.id << " " << rakib.name << " " << rakib.section << " " << rakib.mark << endl;
        }
        else
        {
            cout << akib.id << " " << akib.name << " " << akib.section << " " << akib.mark << endl;
        }
    }

    return 0;
}


// 3
// 1 sakib A 50
// 2 rakib D 96
// 3 akib C 90
// 1 sakib A 50
// 2 rakib D 96
// 3 akib C 96
// 1 sakib A 50
// 2 rakib D 50
// 3 akib C 40