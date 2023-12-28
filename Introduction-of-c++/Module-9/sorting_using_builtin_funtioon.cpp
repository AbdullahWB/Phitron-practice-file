#include <bits/stdc++.h>
using namespace std;

class students
{
public:
    string name;
    int age;
    int marks;
};

bool cmp(students a, students b){
    // if(a.marks >= b.marks){
    //     return true;
    // }else{
    //     return false;
    // }
    // return (a.marks >= b.marks);
    if(a.marks > b.marks){
        return true;
    }else if(a.marks < b.marks){
        return false;
    }else{
        // if(a.age < b.age){
        //     return true;
        // }else{
        //     return false;
        // }
        return (a.age < b.age);
    }
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
    sort(a,a+n,cmp);
    for(int i = 0; i < n; i++){
        cout<< a[i].name << " " << a[i].age << " " << a[i].marks << endl;
    }

    return 0;
}