
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double basicSalary;

public:
    
    Employee(int i, string n, double salary) {
        id = i;
        name = n;
        basicSalary = salary;
    }

    
    void displayDetails() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
    }

    
    double getSalary() {
        return basicSalary;
    }
};


class FullTimeEmployee : public Employee {
public:
    
    FullTimeEmployee(int i, string n, double salary)
        : Employee(i, n, salary) {
    }

    
    double calculateSalary(double basic) {
        return basic;
    }

    
    double calculateSalary(double basic, double bonus) {
        return basic + bonus;
    }

    
    void displaySalary() {
        displayDetails();

        cout << "Salary without bonus: "
             << calculateSalary(getSalary()) << endl;

        cout << "Salary with bonus: "
             << calculateSalary(getSalary(), 5000) << endl;
    }
};

int main() {
    
    FullTimeEmployee e1(101, "Aryan", 30000);

    cout << "EMPLOYEE PAYROLL SYSTEM" << endl;
    e1.displaySalary();

    return 0;
}
