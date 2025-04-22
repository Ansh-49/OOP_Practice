#include <bits/stdc++.h>
using namespace std;

class Employee 
{
public:
    int age;
    int years_of_service;
    double salary;

    Employee(int a, int years, double sal) 
    {
        age = a;
        years_of_service = years;
        salary = sal;
    }

    int getSalaryInThousands() 
    {
        return (salary + 500) / 1000;  
    }
};

int main() 
{
    Employee emp1(25, 3, 45600);
    Employee emp2(35, 8, 78900);

    cout << "Employee 1:" << endl;
    cout << "Age: " << emp1.age << endl;
    cout << "Years of Service: " << emp1.years_of_service << endl;
    cout << "Salary: $" << emp1.salary << endl;
    cout << "Salary in thousands: $" << emp1.getSalaryInThousands() << "K" << endl;

    cout << "\nEmployee 2:" << endl;
    cout << "Age: " << emp2.age << endl;
    cout << "Years of Service: " << emp2.years_of_service << endl;
    cout << "Salary: $" << emp2.salary << endl;
    cout << "Salary in thousands: $" << emp2.getSalaryInThousands() << "K" << endl;

    cout << "\nUpdating Employee 1's information..." << endl;
    emp1.age = 26;
    emp1.years_of_service = 4;
    emp1.salary = 48000;

    cout << "\nEmployee 1 Updated:" << endl;
    cout << "Age: " << emp1.age << endl;
    cout << "Years of Service: " << emp1.years_of_service << endl;
    cout << "Salary: $" << emp1.salary << endl;
    cout << "Salary in thousands: $" << emp1.getSalaryInThousands() << "K" << endl;

    return 0;
} 
