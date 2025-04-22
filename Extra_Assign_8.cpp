#include <bits/stdc++.h>
using namespace std;

class Performance 
{
    public:
    string time;
    int total_seats;
    int booked_seats;

    Performance(string t, int total) 
    {
        time = t;
        totalSeats = total;
        bookedSeats = 0;
    }
    void bookSeats(int seats) {
        if (booked_seats + seats <= total_seats) {
            booked_seats += seats;
            cout << "Successfully booked " << seats << " seats for " << time << " show." << endl;
        } 
        else 
        {
            cout << "Not enough available seats for " << time << endl;
        }
    }

    void showAvailableSeats() {
        cout << "Available seats for " << time << " show: " << (total_seats - booked_seats) << endl;
    }
};
int main() 
{
    Performance show1("1:00 PM", 100);
    Performance show2("5:00 PM", 100);
    Performance show3("8:30 PM", 100);
    int choice, seats;
    cout << "1. Book Seats"<<endl;;
    cout << "2. Show Available Seats"<<endl;
    cout << "3. Exit"<<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1 || choice == 2) {
        cout << "Choose show:"<<endl;;
        cout << "1. 1:00 PM\n2. 5:00 PM\n3. 8:30 PM\n";
        int showChoice;
        cin >> showChoice;

        if (showChoice < 1 || showChoice > 3) {
            cout << "Invalid show choice.";
            continue;
        }
        Performance* selectedShow = nullptr;
        if (showChoice == 1) selectedShow = &show1;
        else if (showChoice == 2) selectedShow = &show2;
            else selectedShow = &show3;
            if (choice == 1) {
                cout << "Enter number of seats to book: ";
                cin >> seats;
                selectedShow->bookSeats(seats);
            } else {
                selectedShow->showAvailableSeats();
            }
        }
   
    cout << "Thank you for using the Cinema Booking System!" << endl;
    return 0;
    }
