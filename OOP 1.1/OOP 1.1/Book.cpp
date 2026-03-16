#include "Book.h"

Book::Book(string ID, string name, string author, bool borrowed, bool reserved, string date, bool overDue)
{
    bookID = ID;
    bookName = name;
    bookAuthor = author;
    this->borrowed = borrowed;
    this->reserved = reserved;
    bookDueDate = date;
    this->overDue = overDue;
}


void Book::setBookID(string value)
{
    bookID = value;
}

void Book::setBookName(string value)
{
    bookName = value;
}

void Book::setBookAuthor(string value)
{
    bookAuthor = value;
}
void Book::setBookDueDate(string value)
{
    bookDueDate = value;
}
string Book::getBookDueDate() const
{
    return bookDueDate;
}
void Book::setOverDue(bool value)
{
    overDue = value;
}
bool Book::getOverDue() const
{
    return overDue;
}
void Book::setBorrowed(bool value)
{
    borrowed = value;
}

void Book::setReserved(bool value)
{
    reserved = value;
}


string Book::getBookID() const
{
    return bookID;
}

string Book::getBookName() const
{
    return bookName;
}

string Book::getBookAuthor() const
{
    return bookAuthor;
}

bool Book::getBorrowed() const
{
    return borrowed;
}

bool Book::getReserved() const
{
    return reserved;
}

