#include "User.h"
#include "library.h"
#include "Book.h"


int borrowedLimit = 5;
int getBorrowedLimit() {
    return borrowedLimit;
}
void setBorrowedLimit(int value) {
    borrowedLimit = value;
}
int reservationExpiration = 3;

int getreservationExpiration() {
    return reservationExpiration;
}
void setreservationExpiration(int value) {
    reservationExpiration = value;
}
int lateFeePenalty = 50;

int getlateFeePenalty() {
    return lateFeePenalty;
}
void setlateFeePenalty(int value) {
    lateFeePenalty = value;
}

void addUser(Library& library)
{
    string tempUserName;
    int tempUserPasskey = 0;
    int tempUserNumber = 0;
    bool tempReserved = false;


    cout << "What is the users name? " << endl;
    if (!(cin >> tempUserName))
    {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else
    {

    }



    cout << "Please assign a user Numeber!" << endl;
    cout << "(less than 100000000)" << endl;
    cin >> tempUserNumber;
    if (tempUserNumber >= 100000000 || tempUserNumber <= 0) {
        cout << "invalid input! Please try again." << endl;

    }
    else
    {

    }



    cout << "Please assign a user Passkey!" << endl;
    cout << "(less than 100000000)" << endl;
    cin >> tempUserPasskey;
    if (tempUserPasskey >= 100000000 || tempUserPasskey <= 0) {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else
    {

    }

    User newUser(tempUserName, tempUserNumber, tempUserPasskey);
    library.addUser(newUser);
    cout << "USER ADDED SUCCESFULLY" << endl;
    return;

}
void User::printAllBooks(Library& library) {
    for (auto& book : library.Books)
    {

        cout << "Book Name: " << book.getBookName() << endl;
        cout << "Book Id: " << book.getBookID() << endl;
        cout << "Book Author: " << book.getBookAuthor() << endl;
        cout << "Book Borrowed: " << endl;
        if (book.getBorrowed() == true)
        {
            cout << "Yes" << endl;

        }
        else
        {
            cout << "No" << endl;
        }
        cout << "Book Reserved: " << endl;
        if (book.getReserved() == true)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        cout << endl;
        cout << endl;

    }
}

