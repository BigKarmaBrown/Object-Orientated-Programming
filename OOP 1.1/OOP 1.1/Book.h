using namespace std;
#pragma once
#include <string>

class Book
{
private:
    string bookName;
    string bookID;
    string bookAuthor;
    bool borrowed;
    bool reserved;
    string bookDueDate;
    bool overDue;
public:
    
    Book(string value, string name, string author, bool borrowed, bool reserved, string date, bool overDue);

   
    void setBookID(string value);
    void setBookName(string value);
    void setBookAuthor(string value);
    void setBookDueDate(string value);
    void setBorrowed(bool value);
    void setReserved(bool value);
    void setOverDue(bool value);
   
    
    string getBookID() const;
    string getBookName() const;
    string getBookAuthor() const;
    string getBookDueDate() const;


    bool getBorrowed() const;
    bool getReserved() const;
    bool getOverDue() const;
};
