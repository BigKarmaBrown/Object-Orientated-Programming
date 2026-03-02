#include "Librarian.h"
#include "Library.h"
#include "Book.h"
void ViewReport(Library& library) //LIBRARIAN AND ADMIN
{

}
void addBook(Library& library) { //LIBRARIAN AND ADMIN

    bool correctDetails;
    string tempBookID;
    string tempBookName;
    string tempBookAuthor;



    cout << "What is the books ID Number? " << endl;
    cin >> tempBookID;
 
    cout << "What is your books name? " << endl;
    cin >> tempBookName;

    cout << "Who is your books Author?  " << endl;
    cin >> tempBookAuthor;
   

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
