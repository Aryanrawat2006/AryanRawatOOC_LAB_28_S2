
#include <iostream>
using namespace std;

class Student
{
protected:
    int rollno;
    char name[50];

public:
    void accept_data()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollno;

        cout << "Enter Student Name: ";
        cin >> name;
    }

    void display_data()
    {
        cout << "\nRoll Number: " << rollno;
        cout << "\nStudent Name: " << name;
    }
};

class StudentMarks : public Student
{
protected:
    float sub1, sub2, sub3, sub4, sub5, sub6;

public:
    void accept_marks()
    {
        cout << "\nEnter marks of 6 subjects: ";
        cin >> sub1 >> sub2 >> sub3 >> sub4 >> sub5 >> sub6;
    }

    void display_marks()
    {
        cout << "\nMarks: "
             << sub1 << " " << sub2 << " "
             << sub3 << " " << sub4 << " "
             << sub5 << " " << sub6;
    }
};

class StudentResult : public StudentMarks
{
    float per;

public:
    void accept_data()
    {
        Student::accept_data();
        accept_marks();
    }

    void display_data()
    {
        Student::display_data();
        display_marks();
    }

    void calculate()
    {
        per = (sub1 + sub2 + sub3 + sub4 + sub5 + sub6) / 6.0;

        cout << "\n\n Total Percentage : " << per;
        cout << "\n ----------------------------------------- \n";
    }
};

int main()
{
    StudentResult str; // Object 'str' is created of derived Class StudentResult

    int cnt, i;

    cout << "\n Enter No. of Students You Want? : ";
    cin >> cnt;

    for (i = 0; i < cnt; i++)
    {
        str.accept_data();
        str.display_data();
        str.calculate();
    }

    return 0;
}
