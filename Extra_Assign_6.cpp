#include <bits/stdc++.h>
using namespace std;

class DB; 

class DM {
public:
    int m;
    float cm;

    DM() : m(0), cm(0) {} 
    DM(int m, float cm)  
    {
        this->m = m;
        this->cm = cm;
    }

    void getDistance() {
        cout << "Enter distance in meters and centimeters:" << endl;
        cout << "Meters: ";
        cin >> m;
        cout << "Centimeters: ";
        cin >> cm;
    }

    void display() {
        cout << "Distance: " << m << " meters and " << cm << " centimeters" << endl;
    }

    friend DM add(DM d1, DB d2);
    friend DB add(DB d1, DM d2);
};

class DB {
public:
    int feet;
    float inches;

    DB() : feet(0), inches(0) {}
    DB(int f, float i)  
    {
        feet = f;
        inches = i;
    }

    void getDistance() {
        cout << "Enter distance in feet and inches:" << endl;
        cout << "Feet: ";
        cin >> feet;
        cout << "Inches: ";
        cin >> inches;
    }

    void display() {
        cout << "Distance: " << feet << " feet and " << inches << " inches" << endl;
    }

    friend DM add(DM d1, DB d2);
    friend DB add(DB d1, DM d2);
};

DM add(DM d1, DB d2) {
    float totalInches = d2.feet * 12 + d2.inches;
    float totalCentimeters = totalInches * 2.54;
    
    int new_m= d1.m + (totalCentimeters / 100);
    float new_cm = d1.cm + fmod(totalCentimeters, 100);
    
    if (new_cm >= 100) {
        new_m += (new_cm/ 100);
        new_cm = fmod(new_cm, 100);
    }
    
    return DM(new_m, new_cm);
}

DB add(DB d1, DM d2) {
    float totalCentimeters = d2.m * 100 + d2.cm;
    float totalInches = totalCentimeters / 2.54;
    
    int newFeet = d1.feet + (totalInches / 12);
    float newInches = d1.inches + fmod(totalInches, 12);
    
    if (newInches >= 12) {
        newFeet += (newInches / 12);
        newInches = fmod(newInches, 12);
    }
    
    return DB(newFeet, newInches);
}

int main() {
    DM d1;
    DB d2;
    
    cout << "Enter first distance (DM):" << endl;
    d1.getDistance();
    
    cout << "Enter second distance (DB):" << endl;
    d2.getDistance();
    
    cout << "Addition result in meters and centimeters:" << endl;
    DM result1 = add(d1, d2);
    result1.display();
    
    cout << "Addition result in feet and inches:" << endl;
    DB result2 = add(d2, d1);
    result2.display();
    
    return 0;
}
