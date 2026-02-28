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
        void printAllBooks(Library& library);

        int getBorrowedLimit() {
            return borrowedLimit;
        }
        void setBorrowedLimit(int value) {
            borrowedLimit = value;
        }
        int getreservationExpiration() {
            return reservationExpiration;
        }
        void setreservationExpiration(int value) {
            reservationExpiration = value;
        }
        int getlateFeePenalty() {
            return lateFeePenalty;
        }
        void setlateFeePenalty(int value) {
            lateFeePenalty = value;
        }


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
        bool hasBooks() 
        {
            return !ownBook.empty();
        }
        User(string name, int number, int passkey) :
            userName(name),
            userNumber(number),
            booksBorrowed(0),
            booksOverDue(0),
            booksReserved(0),
            borrowedLimit(5),
            reservationExpiration(3),
            lateFeePenalty(50),
            userPasskey(passkey) {
        }

        bool checkPasskey(int input)
        {
            return input == userPasskey;
        }

        

    private:
        int userPasskey;
        int booksOverDue;
        int borrowedLimit;
        int lateFeePenalty;
        int reservationExpiration;
};
 