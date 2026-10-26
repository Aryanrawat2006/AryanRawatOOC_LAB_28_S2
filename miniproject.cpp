
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double basicSalary;

public:
    // Constructor
    Employee(int i, string n, double salary) {
        id = i;
        name = n;
        basicSalary = salary;
    }

    // Display employee details
    void displayDetails() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
    }

    // Return basic salary
    double getSalary() {
        return basicSalary;
    }
};

// Inheritance
class FullTimeEmployee : public Employee {
public:
    // Derived class constructor
    FullTimeEmployee(int i, string n, double salary)
        : Employee(i, n, salary) {
    }

    // Function overloading: without bonus
    double calculateSalary(double basic) {
        return basic;
    }

    // Function overloading: with bonus
    double calculateSalary(double basic, double bonus) {
        return basic + bonus;
    }

    // Display salary details
    void displaySalary() {
        displayDetails();

        cout << "Salary without bonus: "
             << calculateSalary(getSalary()) << endl;

        cout << "Salary with bonus: "
             << calculateSalary(getSalary(), 5000) << endl;
    }
};

int main() {
    // Creating an object
    FullTimeEmployee e1(101, "Aryan", 30000);

    cout << "EMPLOYEE PAYROLL SYSTEM" << endl;
    e1.displaySalary();

    return 0;
}
