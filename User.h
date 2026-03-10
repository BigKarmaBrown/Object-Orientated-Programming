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
       //vector<Book*>overDueBooks;


       void setUserName(string value);
       void setBooksBorrowed(int value);
       void setBooksReserved(bool value);

      string getUserName();
      int getbooksBorrowed();
      bool getBookReserved();
      bool hasBooks();

        User(string name, string passkey) :
            userName(name),
            booksBorrowed(0),
            booksOverDue(0),
            booksReserved(false),
            userPasskey(passkey) {
        }

        bool checkPasskey(string input);
        

    private:
        string userPasskey;
        int booksOverDue;
        
};
 