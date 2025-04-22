#include <bits/stdc++.h>
using namespace std;

class Person 
{
public:
    string name;
    int code;

    Person(string n, int c) 
    {
        name = n;
        code = c;
    }
    
    void display() 
    {
        cout << "Name: " << name << endl;
        cout << "Code: " << code << endl;
    }
};

class Account : public Person 
{
public:
    int pay;

    Account(string n = "", int c = 0, int p = 0) : Person(n, c), pay(p) {}
    
    void display()  
    {
        Person::display();
        cout << "Pay: $" << pay << endl;
    }
};

class Admin : public Person 
{
public:
    string exp;

    Admin(string n = "", int c = 0, string e = "") : Person(n, c), exp(e) {}
    
    void display() 
    {
        Person::display();
        cout << "Experience: " << exp << endl;
    }
};

class Master : public Account, public Admin 
{
public:
    Master(string n = "", int c = 0, int p = 0, string e = "") : Account(n, c, p), Admin(n, c, e) {}
    
    void display() 
    {
        cout << "Master Info : "<<endl;;
        Account::display();
        cout << "Experience: " << exp << endl;
    }
};

int main() {
    Master master("Ansh", 1, 100000, "2 years");
    cout << "After creating master object:";
    master.display();
    
    master.pay = 500000;
    master.exp = "3 years";
    cout << "After updating information:";
    master.display();
    
    return 0;
}
