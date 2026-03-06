#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "Book.h"

class Library; 

void addUser(Library& library);


 class User {
    public:
        string userName =  "";
        int booksBorrowed = 0;
        bool booksReserved = false;
        vector<Book*>ownBook;//store borroed books in here
        void printAllBooks(Library& library);



       
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
        User(string name, string passkey) :
            userName(name),
            booksBorrowed(0),
            booksOverDue(0),
            booksReserved(false),
            userPasskey(passkey) {
        }

        bool checkPasskey(string input)
        {
            return input == userPasskey;
        }

        

    private:
        string userPasskey;
        int booksOverDue;
        
};
 