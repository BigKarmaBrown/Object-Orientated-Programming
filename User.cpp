#include "User.h"
#include "library.h"
#include "Book.h"
#include <vector>


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
    string tempUserPasskey = "";


    cout << "What is the users name? " << endl;
    cin >> tempUserName;
    cout << "Please assign a user Passkey!" << endl;
   
    cin >> tempUserPasskey;
 

    User newUser(tempUserName,  tempUserPasskey);
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

