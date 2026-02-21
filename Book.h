using namespace std;
#pragma once
#include <string>

class Book
{
private:
    string bookName;
    int bookID;
    string bookAuthor;
    bool borrowed;
    bool reserved;

public:
    
    Book(int ID, std::string name, std::string author, bool borrowed, bool reserved);

   
    void setBookID(int amount);
    void setBookName(string value);
    void setBookAuthor(string value);
    void setBorrowed(bool value);
    void setReserved(bool value);

    
    int getBookID() const;
    string getBookName() const;
    string getBookAuthor() const;
    bool getBorrowed() const;
    bool getReserved() const;
};
