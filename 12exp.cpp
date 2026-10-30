#include <iostream>
#include <string>
using namespace std;

class Employee {

private:
    // Private data members: cannot be accessed directly
    int id;
    string name;
    double basicSalary;

public:

    Employee() {
        id = 0;
        name = "Unknown";
        basicSalary = 0;
    }

    Employee(int i, string n, double salary) {
        id = i;
        name = n;
        basicSalary = salary;
    }

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getSalary() const {
        return basicSalary;
    }

    void displayDetails() const {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
    }


    virtual double calculateSalary() const = 0;
};

class FullTimeEmployee : public Employee {

public:

    FullTimeEmployee() : Employee() {
    }

    FullTimeEmployee(int i, string n, double salary)
        : Employee(i, n, salary) {
    }

    double calculateSalary(double basic) const {
        return basic;
    }

    double calculateSalary(double basic, double bonus) const {
        return basic + bonus;
    }

    double calculateSalary() const override {
        return calculateSalary(getSalary(), 5000);
    }

    void displaySalary() const {

        displayDetails();

        cout << "Salary without bonus: "
             << calculateSalary(getSalary()) << endl;

        cout << "Salary with bonus: "
             << calculateSalary(getSalary(), 5000) << endl;

        cout << "Final Salary: "
             << calculateSalary() << endl;
    }
};

int main() {

    FullTimeEmployee e1(101, "Aryan", 30000);

    cout << "EMPLOYEE PAYROLL SYSTEM" << endl;
    cout << "------------------------" << endl;

    e1.displaySalary();

    Employee* ptr = &e1;

    cout << "\nSalary using base class pointer: "
         << ptr->calculateSalary() << endl;

    return 0;
}