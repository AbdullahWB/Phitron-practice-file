#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int cls;
    char section;
    int id;
    int math_marks;
    int eng_marks;
};

bool cmp(Student a, Student b){
    int total_marks_a=a.math_marks+a.eng_marks;
    int total_marks_b=b.math_marks+b.eng_marks;

    if(total_marks_a==total_marks_b){
        return a.id<b.id;
    }

    return total_marks_a>total_marks_b;
};

int main()
{
    int n;
    cin >> n;

    Student student[n];
    for(int i=0; i<n; i++){
        cin>> student[i].name>>student[i].cls>>student[i].section>>student[i].id>>student[i].math_marks>>student[i].eng_marks;
    }

    sort(student,student+n,cmp);

    for(int i=0; i<n; i++){
        cout<<student[i].name<< " " << student[i].cls << " " << student[i].section << " " << student[i].id << " " <<student[i].math_marks << " " << student[i].eng_marks << endl;
    }

    return 0;
}