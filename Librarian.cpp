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
