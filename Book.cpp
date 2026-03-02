#include "Book.h"

Book::Book(string ID, string name, string author, bool borrowed, bool reserved)
{
    bookID = ID;
    bookName = name;
    bookAuthor = author;
    this->borrowed = borrowed;
    this->reserved = reserved;
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

