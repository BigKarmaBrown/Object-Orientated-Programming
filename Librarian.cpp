#include "Librarian.h"
#include "Library.h"
#include "Book.h"
void ViewReport(Library& library) //LIBRARIAN AND ADMIN
{

}
void addBook(Library& library) { //LIBRARIAN AND ADMIN

    bool correctDetails;
    int tempBookID = 0;
    string tempBookName;
    string tempBookAuthor;



    cout << "What is the books ID Number? " << endl;
    cin >> tempBookID;
    if (tempBookID >= 100000000 || tempBookID <= 0) {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else {

    }

    cout << "What is your books name? " << endl;

    if (!(cin >> tempBookName))
    {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else {

    }

    cout << "Who is your books Author?  " << endl;
    if (!(cin >> tempBookAuthor))
    {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else {

    }

    cout << "Your books ID is: " << tempBookID << endl;
    cout << "Your books title is: " << tempBookName << endl;
    cout << "Your books Author is: " << tempBookAuthor << endl;
    cout << endl;

    cout << "Are these detials correct? true or false " << endl;
    cin >> correctDetails;
    if (!correctDetails) {
        cout << "Please try again. " << endl;
        return;
    }

    Book newBook(tempBookID, tempBookName, tempBookAuthor, false, false);
    library.addBook(newBook);
    cout << "ADDED BOOK SUCCESFULLY" << endl;
    return;






}
void removeBook(Library& library) //LIBRARIAN AND ADMIN
{/*
    bool correctDetails;
    string tempName;
    int tempID;
    string yesNo;

    cout << "Which Book Would you like to get rid of?" << endl;
    cin >> tempName;



    if (tempName == library.Books.getbookName(name)) {
        cout << "Whats the Books ID?" << endl;
        cin >> tempID;
        if (tempID == library.Books.getbookID(bookID))
        {
            erase()
        }
    }


    cout << "Whats the Books ID?" << endl;
    cin >> tempID;

    //compare tempID to User Library


    cout << "Has someone got this book borrowed?" << endl;
    cout << "Yes or No? " << endl;
    cin >> yesNo;

    if (yesNo == "Yes" || yesNo == "yes" || yesNo == "Y" || yesNo == "y" || yesNo == "YES")
    {
        cout << "Wait until book is returned" << endl;
        return;
    }
    else
    {

    }

    cout << "Are these details correct? " << endl;
    cout << "Book Name: " << tempName << endl;
    cout << "Book ID: " << tempID << endl;
    cin >> correctDetails;
    if (!correctDetails) {
        cout << "Please try again. " << endl;
        return;
    }
    cout << "Book succesfully removed!" << endl;*/
}

