#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isavail;
    int bookcount;

public:
    // Constructor
    Book(string name, string authorname, string code) {
        title = name;
        author = authorname;
        ISBN = code;
        isavail = true;
        bookcount = 0;
    }

    void borrowbook() {
        int borrow;
        cout << "Enter 1 to borrow and 2 to skip: " << endl;
        cin >> borrow;

        if (borrow == 1) {
            if (isavail) {
                cout << "Book borrowed successfully. ISBN: " << ISBN << endl;
                bookcount++;
                isavail = false;
            } else {
                cout << "Book is not available right now." << endl;
            }
        } else {
            cout << "Skipping..." << endl;
        }
    }

    int getcount() {
        return bookcount;
    }

    void returnbook() {
        string returns;
        cout << "Enter 'r' to return book or 'x' to skip: " << endl;
        cin >> returns;

        if (returns == "r" || returns == "R") {
            cout << "Book returned. Thank you!" << endl;
            isavail = true;
        } else {
            cout << "Skipped." << endl;
        }
    }

    void ratings() {
        float rateus;
        cout << "Would you like to rate us? (0 to skip): ";
        cin >> rateus;

        if (rateus == 0) {
            cout << "Skipped." << endl;
        } else if (rateus < 0 || rateus > 5) {
            cout << "Invalid rating!" << endl;
        } else {
            cout << "You rated: " << rateus << endl;
            cout << "Thanks for your support!" << endl;
        }
    }

    void displayinfo() {
        cout << "\nTitle: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Availability: " << (isavail ? "Available" : "Not Available") << endl;
        cout << "Times borrowed: " << bookcount << endl;
    }
};

int main() {
    cout << "Welcome to the Extremers Book Shop\n" << endl;

    Book b1("Atomic Habit", "M. Maxed", "012025");
    Book b2("The King", "Apul Bash", "022025");

    int number, selection;

    while (true) {
        cout << "\nEnter 1 for book details, 0 to exit: ";
        cin >> number;

        if (number == 1) {
            cout << "\nAvailable Books:\n";
            cout << "1. Atomic Habit\n";
            cout << "2. The King\n";
            cout << "Select a book: ";
            cin >> selection;

            if (selection == 1) {
                b1.displayinfo();
                b1.borrowbook();
                b1.returnbook();
                b1.ratings();
                b1.displayinfo();
            } 
            else if (selection == 2) {
                b2.displayinfo();
                b2.borrowbook();
                b2.returnbook();
                b2.ratings();
                b2.displayinfo();
            } 
            else {
                cout << "Invalid selection!" << endl;
            }
        } 
        else if (number == 0) {
            cout << "Exiting program..." << endl;
            break;
        } 
        else {
            cout << "Invalid input!" << endl;
        }

        string x;
        cout << "\nPress 'c' to continue or 'x' to exit: ";
        cin >> x;

        if (x == "x" || x == "X") {
            cout << "Exiting..." << endl;
            break;
        }
    }

    return 0;
}