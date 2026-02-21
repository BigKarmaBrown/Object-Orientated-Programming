#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "Book.h"

class Library; 

void addUser(Library& library);


 class User {
    public:
        string userName;
        int userNumber;
        int booksBorrowed;
        bool booksReserved;
        vector<Book*>ownBook;//store borroed books in here

        void setUserNumber(int amount)
        {
            userNumber = amount;
        }

        void setUserName(string value)
        {
            userName = value;
        }

        void setBooksBorrowed(int value)
        {
            booksBorrowed = value;
        }

        void setBooksReserved(bool value)
        {
            booksReserved = value;
        }


        int getUserNumber()
        {
            return userNumber;
        }

        string getUserName()
        {
            return userName;
        }

        int getbooksBorrowed()
        {
            return booksBorrowed;
        }

        bool getBookReserved()
        {
            return booksReserved;
        }

        User(string name, int number, int passkey) :
            userName(name),
            userNumber(number),
            booksBorrowed(0),
            booksOverDue(0),
            booksReserved(0),
            userPasskey(passkey) {
        }

        bool checkPasskey(int input)
        {
            return input == userPasskey;
        }

        

    private:
        int userPasskey;
        int booksOverDue;


};
 