#include <iostream>
#include <string>
using namespace std;

int MAX_BOOKS = 1000;  

class Book {
public:
    int classmark;      
    string status;      
    int isValid;   

    Book() 
    {
        classmark = 0;
        status = "";
        isValid = 0;  
    } 

    Book(int mark) {
        classmark = mark;
        status = "on_shelf";
        isValid = 1;  
    }

    void loan() {
        status = "on_loan";
    }

    void missing() {
        status = "missing";
    }

    void reserved() {
        status = "reserved";
    }

    void returned() {
        status = "on_shelf";
    }

    string state() 
    {
        return status;
    }

    int getClassmark() 
    {
        return classmark;
    }

    int isValidBook() 
    {  
        return isValid;
    }
};

class Library {
public:
    Book books[MAX_BOOKS];
    int book_count;

    Library()
    {
        book_count = 0;
    }

    void addBook(int classmark) 
    {  
        if (book_count >= MAX_BOOKS) {
            cout << "Library is full!" << endl;
            return;
        }
        books[book_count] = Book(classmark);
        book_count++;
    }

    void checkOutBook(int classmark) 
    {  
        for (int i = 0; i < book_count; i++) {
            if (books[i].isValidBook() && books[i].getClassmark() == classmark && books[i].state() == "on_shelf") 
            {
                books[i].loan();
                cout << "Book checked out successfully" << endl;
                return;
            }
        }
        cout << "Could not check out book" << endl;
    }

    void reserveBook(int classmark) 
    {  
        for (int i = 0; i < book_count; i++) {
            if (books[i].isValidBook() && books[i].getClassmark() == classmark && books[i].state() == "on_loan") 
            {
                books[i].reserved();
                cout << "Book reserved successfully" << endl;
                return;
            }
        }
        cout << "Could not reserve book" << endl;
    }

    void returnBook(int classmark) 
    {  
        for (int i = 0; i < book_count; i++) {
            if (books[i].isValidBook() && books[i].getClassmark() == classmark && books[i].state() == "on_loan") 
            {
                books[i].returned();
                cout << "Book returned successfully" << endl;
                return;
            }
        }
        cout << "Could not return book" << endl;
    }

    string getBookStatus(int classmark) 
    {
        for (int i = 0; i < book_count; i++) {
            if (books[i].isValidBook() && books[i].getClassmark() == classmark) {
                return books[i].state();
            }
        }
        return "Book not found";
    }

    void printSummary() 
    {
        int onLoan = 0;
        int reserved = 0;
        int onShelf = 0;

        for (int i = 0; i < book_count; i++) {
            if (!books[i].isValidBook()) continue;
            
            if (books[i].state() == "on_loan")
            { 
                onLoan++;
            }
            else if (books[i].state() == "reserved") 
            {
                reserved++;
            }
            else if (books[i].state() == "on_shelf") 
            {
                onShelf++;
            }
        }

        cout << "Library Summary: " << endl;
        cout << "Books in library = " << book_count << endl;
        cout << "Books on loan = " << onLoan << endl;
        cout << "Books reserved = " << reserved << endl;
        cout << "Books on shelves = " << onShelf << endl;
    }
};

int main() 
{
    Library lib;

    for (int i = 1; i <= 100; i++) 
    {
        lib.addBook(i);
    }

    cout << "Testing library operations:" << endl;
    lib.checkOutBook(1);
    lib.checkOutBook(2);
    lib.reserveBook(1);
    cout << "Status of book 1: " << lib.getBookStatus(1) << endl;
    lib.returnBook(2);

    lib.printSummary();

    return 0;
}

