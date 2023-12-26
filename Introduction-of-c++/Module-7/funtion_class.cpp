#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;
    int mark1;
    int mark2;
    Person(string nm, int ag, int m1, int m2){
        name = nm;
        age = ag;
        mark1 = m1;
        mark2= m2;
    }
    int totalMark(){
        return mark1+mark2;
    }
};

int
main()
{
    Person abdullah("Mohammad Abdullah", 21, 89,86);
    cout<< abdullah.totalMark()<<endl;
    return 0;
}