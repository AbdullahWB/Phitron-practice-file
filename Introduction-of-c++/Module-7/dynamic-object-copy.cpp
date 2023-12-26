#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    string name;
    int age;
    Person(string nm, int ag){
        name = nm;
        age = ag;
    }
};

int
main()
{
    Person* abdullah=new Person("Abdullah", 21);
    Person* Mohammad=new Person("Mohammad", 21);
    *abdullah=*Mohammad;
    delete Mohammad;
    cout<<abdullah->name<< " "<< abdullah->age<< endl;
    return 0;
}