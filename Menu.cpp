#include "Menu.h"
#include "Admin.h"
#include "Librarian.h"
#include "User.h"
#include "Library.h"
#include "Book.h"
#include <iostream>
using namespace std;








void loginMenu(Library& library) {

    int passkey = 0;
    string yesNo;

    cout << "Do you have an account?" << endl;
    cout << "Yes or No? " << endl;
    cin >> yesNo;
    if (yesNo == "No" || yesNo == "no" || yesNo == "N" || yesNo == "n" || yesNo == "NO")
    {
        cout << "Please Create an account. " << endl;
        addUser(library);
        return;
    }

    if (yesNo == "Yes" || yesNo == "yes" || yesNo == "Y" || yesNo == "y" || yesNo == "YES")
    {
        typeMenu(library);

    }
    else
    {
        cout << "Invalid Input, Please try again!" << endl;
        loginMenu(library);
        return;
    }

}
void typeMenu(Library& library)
{
    while (true){
    int ans;
    cout << "Which type of account do you have? " << endl;
    cout << "Type One of the following numbers: " << endl;
    cout << "1: User" << endl;
    cout << "2: Librarian" << endl;
    cout << "3: Admin" << endl;
    cout << "4: Back to Main Page" << endl;

    if (!(cin >> ans)) {
        cout << "Invalid Input" << endl;
        cin.clear();
    }

    switch (ans)
    {
    case 1:
    {
        usernameLogin(library);
        break;
    }

    case 2:
    {
        LibrarianLoginMenu(library);
        break;
    }
    case 3:
    {
        AdminLoginMenu(library);
        break;
    }
    case 4:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LOGGING OUT!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        loginMenu(library);
    }

    default:
    {
        cout << "INVALID CHOICE! PLEASE INPUT BETWEEN 1 AND 4! " << endl;

    }
    }
    }

}
void LibrarianLoginMenu(Library& library){

    string passname;
    int passkey;

    do {

        cout << "What is the Users Name? " << endl;
        cout << "(Type 'Back' for Main Menu)" << endl;
        cin >> passname;


        if (passname == "Back" || passname == "back") {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RETURNING MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            return;
        }

        Librarian* user = library.findLibrarianByName(passname);
        if (user == nullptr) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ USER NAME INVALID ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            continue;
        }
        cout << "Enter passkey: " << endl;
        cin >> passkey;

        if (user->checkPasskey(passkey)) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~USER NAME CORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            LibrarianMainMenu(user, library);
            return;
        }
        else {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NAME INCORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

    } while (true);

}
void AdminLoginMenu(Library& library)
{

    string passname;
    int passkey;

    do {

        cout << "What is the Users Name? " << endl;
        cout << "(Type 'Back' for Main Menu)" << endl;
        cin >> passname;


        if (passname == "Back" || passname == "back") {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RETURNING MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            return;
        }

        Admin* user = library.findAdminByName(passname);
        if (user == nullptr) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ USER NAME INVALID ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            continue;
        }
        cout << "Enter passkey: " << endl;
        cin >> passkey;

        if (user->checkPasskey(passkey)) {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~USER NAME CORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            AdminMainMenu(user, library);
            return;
        }
        else {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NAME INCORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }

    } while (true);

}
void BrowseBooksMenu(User* user, Library& library)  //all
{
    while (true) {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        for (auto& book : library.Books)
        {

            cout << "Book Name: " << book.getBookName() << endl;
            cout << "Book Id: " << book.getBookID() << endl;
            cout << "Book Author: " << book.getBookAuthor() << endl;
            cout << "Book Borrowed: ";
            if (book.getBorrowed() == true)
            {
                cout << "Yes" << endl;

            }
            else
            {
                cout << "No" << endl;
            }
            cout << "Book Reserved: ";
            if (book.getReserved() == true)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            cout << endl;
            cout << endl;

        }
        cout << "Type Book ID to borrow book" << endl;
        cout << "(Type 0 to Go back)" << endl;
        int choice;
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        for (auto& book : library.Books)
        {
            if (book.getBookID() == choice)
            {
                if (book.getBorrowed())
                {
                    cout << "Sorry, book is already borrowed." << endl;
                    break;
                }
                else {
                    book.setBorrowed(true);
                    user->ownBook.push_back(&book);
                    user->booksBorrowed += 1;

                    cout << "Book borrowed successfully!" << endl;
                }
                break;
            }
        }

        cout << "Invalid Book ID." << endl;

    }
    

}
void ViewOwnBooksMenu(User* user, Library& library)  //all
{
    string word;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OWN BOOKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "(type to go back)" << endl;
    cout << " " << endl;
    cout << " " << endl;
    for (auto& ownBooks : library.Books) {
        cout << ownBooks.getBookName() << endl;
        cout << ownBooks.getBookAuthor() << endl;
        cout << ownBooks.getBookID() << endl;
        cout << " " << endl;
    }
    
    if (!(cin >> word)) {
        cout << "Invalid Input" << endl;
        cin.clear();
        return;
    }
    return;

}
void ChangeBooksMenu(Library& library) //LIBRARIAN AND ADMIN
{
    int option;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CHANGE BOOKS MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Pick an Option" << endl;
    cout << "1. Add Book to system" << endl;
    cout << "2. Remove Book from system" << endl;
    cout << "3. Go back" << endl;
    cin >> option;
    switch (option) {

    case  1:
    {
        addBook(library);
        break;
    }
    case 2:
    {
        removeBook(library);
        break;
    }

    case 3:
    {
        return;
        break;
    }

    default:
    {
        cout << "INVALID CHOICE! PLEASE INPUT BETWEEN 1 AND 3! " << endl;

    }

    }
}
void AddAccountMenu(Library& library)
{
    while (true){
    int option;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ADD ACCOUNTS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "Pick an option for an account to add." << endl;
    cout << "1: User" << endl;
    cout << "2: Librarian" << endl;
    cout << "3: Admin" << endl;
    cout << "4: Go Back" << endl;
    cin >> option;
    switch (option) {

    case  1:
    {
        addUser(library);
        break;
    }
    case 2:
    {
        addLibrarian(library);
        break;
    }

    case 3:
    {
        addAdmin(library);
        break;
    }
    case 4:
    {
        return;
        break;
    }

    default:
    {
        cout << "INVALID CHOICE! PLEASE INPUT BETWEEN 1 AND 4! " << endl;

    }
    }
    }
}
void ReservationsMenu(Library& library) //LIBRARIAN AND ADMIN
{

}
void ManageUserAccountsMenu(Library& library)  // ADMIN
{
    while (true){
    int option;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MANAGE USER ACCOUNTS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Pick an Option" << endl;
    cout << "1. Add Book to system" << endl;
    cout << "2. Remove Book from system" << endl;
    cout << "3. Go back" << endl;
    cin >> option;
    switch (option) {

    case  1:
    {
        AddAccountMenu(library);
        break;
    }
    case 2:
    {
        removeUser(library);
        break;
    }

    case 3:
    {
        return;
        break;
    }

    default:
    {
        cout << "INVALID CHOICE! PLEASE INPUT BETWEEN 1 AND 3! " << endl;

    }
    }
    }
}
void ChangeSystemLimitationsMenu(Library& library)  // ADMIN
{

}
void UserMainMenu(User* user, Library& library)
{
    while(true)
    {
        int menuInput;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                                    MAIN MENU                                       " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Type Number For Option Below" << endl;
        cout << "1: Browse Books" << endl;
        cout << "2: Manage Own Books" << endl;
        cout << "3: Log Out" << endl;
        if (!(cin >> menuInput)) {
            cout << "Invalid Input" << endl;
            cin.clear();
            return;
        }
    
        switch (menuInput)
        {
         case 1:
        {
           BrowseBooksMenu(user, library);
            break;
        }

        case 2:
        {
            ViewOwnBooksMenu(user, library);
            break;
        }

        case 3:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LOGGING OUT!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            return;
            break;
        }

        default:
        {
            cout << "INVALID CHOICE! PLEASE INPUT BETWEEN 1 AND 3! " << endl;
            return;
        }

        }
        }
    
}
void LibrarianMainMenu(Librarian* librarain, Library& library)
{
    while (true){
    int menuInput;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                             LIBRARIAN MAIN MENU                                    " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Type Number For Option Below" << endl;
    cout << "1: Browse Books" << endl;
    cout << "2: Manage Own Books" << endl;
    cout << "3: Change Books On System" << endl;
    cout << "4: Handle Reservation Requests" << endl;
    cout << "5: View Report" << endl;
    cout << "6: Log Out" << endl;
    if (!(cin >> menuInput)) {
        cout << "Invalid Input" << endl;
        cin.clear();
        return;
    }

    switch (menuInput)
    {
    case 1:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BROWSE BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        BrowseBooksMenu(librarain, library);
        break;
    }

    case 2:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VIEW OWN BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        ViewOwnBooksMenu(librarain, library);
        break;
    }


    case 3:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CHANGE BOOKS ON SYSTEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        ChangeBooksMenu(library);
        break;
    }
    case 4:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RESERVASTIONS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        ReservationsMenu(library);
        break;
    }
    case 5:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~REPORT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        ViewReport(library);
        break;
    }
    case 6:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LOGGING OUT!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        loginMenu(library);
        break;
    }

    default:
    {
        cout << "INVALID CHOICE! PLEASE INPUT BETWEEN 1 AND 6! " << endl;
        return;
    }
    }
    }
}
void AdminMainMenu(Admin* admin, Library& library)
{
    while (true) {
        int menuInput;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                             ADMIN MAIN MENU                                    " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Type Number For Option Below" << endl;
        cout << "1: Browse Books" << endl;
        cout << "2: Manage Own Books" << endl;
        cout << "3: Change Books On System" << endl;
        cout << "4: Handle Reservation Requests" << endl;
        cout << "5: View Report" << endl;
        cout << "6: Manage User Accounts" << endl;
        cout << "7: Manage System Limitations" << endl;
        cout << "8: Log Out" << endl;
        if (!(cin >> menuInput))
        {
            cout << "Invalid Input" << endl;
            cin.clear();
            return;
        }

        switch (menuInput)
        {
        case 1:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BROWSE BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            BrowseBooksMenu(admin, library);
            break;
        }

        case 2:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VIEW OWN BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            ViewOwnBooksMenu(admin, library);
            break;
        }


        case 3:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CHANGE BOOKS ON SYSTEM~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            ChangeBooksMenu(library);
            break;
        }
        case 4:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RESERVASTIONS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            ReservationsMenu(library);
            break;
        }
        case 5:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~REPORT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            ViewReport(library);
            break;
        }
        case 6:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MANAGE USER ACCOUNTS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            ManageUserAccountsMenu(library);
            break;
        }
        case 7:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CHANGE SYSTEM LIMITATIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            ChangeSystemLimitationsMenu(library);
            break;
        }
        case 8:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~LOGGING OUT!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            loginMenu(library);
            break;
        }

        default:
        {
            cout << "INVALID CHOICE! PLEASE INPUT BETWEEN 1 AND 3! " << endl;
            return;
        }



        }
    }
}
    void usernameLogin(Library& library) {
        string passname;
        int passkey;

        do {

            cout << "What is the Users Name? " << endl;
            cout << "(Type 'Back' for Main Menu)" << endl;
            cin >> passname;


            if (passname == "Back" || passname == "back") {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RETURNING MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                return;
            }

            User* user = library.findUserByName(passname);
            if (user == nullptr) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ USER NAME INVALID ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                continue;
            }
            cout << "Enter passkey: " << endl;
            cin >> passkey;

            if (user->checkPasskey(passkey)) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~USER NAME CORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                UserMainMenu(user, library);
                return;
            }
            else {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NAME INCORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            }

        }while (true);
    }



