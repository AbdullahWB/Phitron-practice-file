#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int id;
    string name;
    char section;
    int marks;

    // Parameterized constructor
    Student(int _id, string _name, char _section, int _marks)
    {
        id = _id;
        name = _name;
        section = _section;
        marks = _marks;
    }
};

void findHighestStudent(Student &a, Student &b, Student &c)
{
    // Check which student has the highest marks
    if (a.marks > b.marks && a.marks > c.marks)
    {
        cout << a.id << " " << a.name << " " << a.section << " " << a.marks << endl;
    }
    else if (b.marks > a.marks && b.marks > c.marks)
    {
        cout << b.id << " " << b.name << " " << b.section << " " << b.marks << endl;
    }
    else if (c.marks > a.marks && c.marks > b.marks)
    {
        cout << c.id << " " << c.name << " " << c.section << " " << c.marks << endl;
    }
    else
    {
        // If there is a tie, check for the student with the smaller ID
        if (a.marks == b.marks && a.marks == c.marks)
        {
            int minID = std::min({a.id, b.id, c.id}); // Use std::min
            cout << minID << " ";

            if (minID == a.id)
                cout << a.name << " " << a.section << " " << a.marks << endl;
            else if (minID == b.id)
                cout << b.name << " " << b.section << " " << b.marks << endl;
            else
                cout << c.name << " " << c.section << " " << c.marks << endl;
        }
        else
        {
            // Rest of the code remains the same
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int id1, marks1, id2, marks2, id3, marks3;
        string name1, name2, name3;
        char section1, section2, section3;

        // Input for student 1
        cin >> id1 >> name1 >> section1 >> marks1;

        // Input for student 2
        cin >> id2 >> name2 >> section2 >> marks2;

        // Input for student 3
        cin >> id3 >> name3 >> section3 >> marks3;

        // Create Student objects for each student
        Student student1(id1, name1, section1, marks1);
        Student student2(id2, name2, section2, marks2);
        Student student3(id3, name3, section3, marks3);

        // Call the function to find and print the details of the student with the highest marks
        findHighestStudent(student1, student2, student3);
    }

    return 0;
}
