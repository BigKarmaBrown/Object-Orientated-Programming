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

public:
    
    Book(string value, std::string name, std::string author, bool borrowed, bool reserved);

   
    void setBookID(string value);
    void setBookName(string value);
    void setBookAuthor(string value);
    void setBorrowed(bool value);
    void setReserved(bool value);

    
    string getBookID() const;
    string getBookName() const;
    string getBookAuthor() const;
    bool getBorrowed() const;
    bool getReserved() const;
};
