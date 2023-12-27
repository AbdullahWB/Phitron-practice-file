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
    for (int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++){
            if(a[i].marks < a[j].marks){
                swap(a[i], a[j]);
            }
            if(a[i].marks == a[j].marks){
                if(a[i].age > a[j].age){
                    swap(a[i], a[j]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<< a[i].name << " " << a[i].age << " " << a[i].marks << endl;
    }

    return 0;
}