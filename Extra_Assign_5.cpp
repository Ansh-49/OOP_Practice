#include <bits/stdc++.h>
using namespace std;

class Books 
{
    string author, title, publisher;
    int price;
    int stock;

    public:
    Books(string a, string t, string p, int pri, int s) 
    {
        author = a;
        title = t;
        publisher = p;
        price = pri;
        stock = s;
    }

    void displayDetails() 
    {
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author<<endl;
        cout<<"Publisher: "<<publisher<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Stock: "<<stock<<"copies"<<endl;
    }

    bool purchaseBook(string t, string a, int copies) 
    {
        if (title == t && author == a) 
        {
            if (stock >= copies) 
            {
                cout<<"Book is available."<<endl;
                cout<<"Total cost: " <<price * copies<<endl;
                stock -= copies;
                return true;
            } 

            else 
            {
                cout << "Required Book / number of copies not available." << endl;
                return true;
            }
        } 

        else 
        {
            return false;
        }
    }
};

int main() 
{
    Books book1("Ansh", "English", "Self", 10.5, 5);
    Books book2("Author2", "Title2", "Publisher2", 15.0, 3);
    Books book3("Author3", "Title3", "Publisher3", 20.0, 2);

    string title, author;
    int copies;

    cout<<"Enter the title of the book: ";
    getline(cin, title);

    cout<<"Enter the author of the book: ";
    getline(cin, author);

    cout<<"Enter the number of copies required: ";
    cin>>copies;

    bool found = false;
    
    if (book1.purchaseBook(title, author, copies)) {
        found = true;
    }
    else if (book2.purchaseBook(title, author, copies)) {
        found = true;
    }
    else if (book3.purchaseBook(title, author, copies)) {
        found = true;
    }

    if (!found) 
    {
        cout << "Book not found in inventory." << endl;
    }
    return 0;
}
