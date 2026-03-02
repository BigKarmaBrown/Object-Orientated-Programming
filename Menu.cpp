#include "Menu.h"
#include "Admin.h"
#include "Librarian.h"
#include "User.h"
#include "Library.h"
#include "Book.h"
#include <iostream>
using namespace std;
#include <string>


void loginMenu(Library& library) {
    system("CLS");
    string passkey = "";
    string yesNo = "";

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
    system("CLS");
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
void usernameLogin(Library& library) {
        string passname = "";
        string passkey = "";
        
        system("CLS");
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
                User* user = Library::currentUser;
                UserMainMenu(library);
                cin.clear();
                return;
            }
            else {
                cout << "~~y~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NAME INCORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
               
            }
            cin.ignore();
        }while (true);
    }
void LibrarianLoginMenu(Library& library){

    string passname = "";
    string passkey = "";
    system("CLS");
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
            User* user = Library::currentUser;
            LibrarianMainMenu(user, library);
            return;
        }
        else {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NAME INCORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
      
        }
        cin.ignore();
    } while (true);

}
void AdminLoginMenu(Library& library)
{
    system("CLS");
    string passname = "";
    string passkey = "";

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
            User* user = Library::currentUser;
            AdminMainMenu(user, library);
            return;
        }
        else {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ NAME INCORRECT AND PASSKEY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
        cin.ignore();
    } while (true);

}
void BrowseBooksMenu(Library& library)  //all
{
    
    while (true)
    {
        system("CLS");
        User* user = library.getCurrentUser();
        string yesNo = "";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Type 'Back' to go back a menu!" << endl;
        user->printAllBooks(library);
        string choice;
        cin >> choice;
        if (choice == "Back" || choice == "back")
        {
            return;
        }
       
        for (auto& book : library.Books)
        {
            if (choice == book.getBookName())
            {
                if (user->booksBorrowed >= user->getBorrowedLimit())
                {
                    cout << "Sorry, Max books borrowed!" << endl;
                    break;
                }
                
                if (!book.getBorrowed())
                {
                book.setBorrowed(true);
                user->ownBook.push_back(&book);
                user->booksBorrowed += 1;
                cout << "Book borrowed successfully!" << endl;
                break;
                }
                if (book.getReserved() == true) 
                {
                    cout << "Sorry, book is already reserved" << endl;
                    break;
                }
                if (user->getBookReserved() == true) {
                    cout << "You can only reserve one book at a time" << endl;
                    continue;
                }
                if (user->getBookReserved() == false) {
                    user->setBooksReserved(true);
                    cout << "Book reserve request sent!" << endl;
                    return;
                }
                else
                {
                    cout << "Invalid Input, Please try again!" << endl;
                    return;
                }
                break;
            }
           
        }

        
    }

};
void ViewOwnBooksMenu(Library& library)  //all
{
    User* user = library.getCurrentUser();
    system("CLS");
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OWN BOOKS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "(type to go back)" << endl;
    string word = "";
    if (!(user->hasBooks())) 
    {
        cout << " You have no books borrowed." << endl;
        cout << "Borrow a book to see it here." << endl;
        cout << "Type to go back!" << endl;
        if (!(cin >> word)) {
            cout << "Invalid Input" << endl;
            cin.clear();
            return;
        }
    }
    else {
           
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
    
   
}
void ChangeBooksMenu(Library& library) //LIBRARIAN AND ADMIN
{
    int option;
    system("CLS");
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
        library.removeBook();
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
    system("CLS");
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
    system("CLS");
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MANAGE USER ACCOUNTS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Pick an Option" << endl;
    cout << "1. Add User to system" << endl;
    cout << "2. Remove User from system" << endl;
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
        library.removeUser();
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
void ChangeSystemLimitationsMenu(Library& library)
{

    while (true)
    {
        system("CLS");
        int ans;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~CHANGE SYSTEM LIMITATIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                What system limitation would u like to change?" << endl;
        cout << " " << endl;
        cout << " " << endl;
        cout << "1: Change Borrowing Books Limit" << endl;
        cout << "2: Change Late Penalty" << endl;
        cout << "3: Change Reservation Expiration" << endl;
        cout << "4: Back" << endl;

        if (!(cin >> ans))
        {
            cout << "Invalid Input" << endl;
            cin.clear();
        }

        switch (ans)
        {
        case 1:
        {
            cout << "Change Borrowing Books Limit" << endl;
            changeBooksLimitMenu(library);
            break;
        }

        case 2:
        {
            cout << "Change Late Penalty" << endl;
            changeLatePenaltyMenu(library);
            break;
        }
        case 3:
        {
            cout << "Change Reservation Expiration" << endl;
            changeReservationsExpirationMenu(library);
            break;
        }
        case 4:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~Going Back~~~~~~~~~~~~~~~~~~~~~~" << endl;
            return;
            break;
        }
        default:
        {
            cout << "invalid input " << endl;
        }
        }
    }
}
void changeBooksLimitMenu(Library& library)
{
    system("CLS");
    User* user = library.getCurrentUser();
    cout << "Change Borrowing Books Limit" << endl;
    cout << "Current Quantity: " << user->getBorrowedLimit() << endl;
    int change;
    cout << " " << endl;
    cout << "Input new Limit" << endl;
    cin >> change;
    if (!(cin >> change))
    {
        cout << "invalid input! " << endl;
        cin.clear();
    }
    else 
    {
        user->setBorrowedLimit(change);
        cout << "New limit has been set!" << endl;
        return;
    }
    
}
void changeLatePenaltyMenu(Library& library)
{
    system("CLS");
    User* user = library.getCurrentUser();
    cout << "Change Late Penalty" << endl;
    cout << "Current Late Fee: " << user->getlateFeePenalty() << endl;
    int change;
    cout << " " << endl;
    cout << "Input new Fee" << endl;
    cin >> change;
    if (!(change))
    {
        cout << "invalid input! " << endl;
        cin.clear();
    }
    else
    {
        user->setlateFeePenalty(change);
        cout << "New late fee has been set to: "<< user->getlateFeePenalty() << endl;
        return;
    }
}
void changeReservationsExpirationMenu(Library & library){
    system("CLS");
    User* user = library.getCurrentUser();
    cout << "Change Reservation Expiration" << endl;
    cout << "Current Days of expiration: " << user->getreservationExpiration() << endl;
    int change;
    cout << " " << endl;
    cout << "Input new Limit" << endl;
    cin >> change;
    if (!(cin >> change))
    {
        cout << "invalid input! " << endl;
        cin.clear();
    }
    else
    {
        user->setreservationExpiration(change);
        cout << "New Expiration Set!" << endl;
        return;
    }
}
void UserMainMenu(Library& library){
    while(true)
    {
        User* user = library.getCurrentUser();
        int menuInput;
        system("CLS");
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
           BrowseBooksMenu(library);
            break;
        }

        case 2:
        {
            ViewOwnBooksMenu(library);
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
void LibrarianMainMenu(User* user, Library& library)
{
    while (true){

    int menuInput;
    system("CLS");
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
        BrowseBooksMenu(library);
        break;
    }

    case 2:
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VIEW OWN BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        ViewOwnBooksMenu(library);
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
void AdminMainMenu(User* user, Library& library)
{
    while (true) {
        int menuInput;
        system("CLS");
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
            BrowseBooksMenu(library);
            break;
        }

        case 2:
        {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~VIEW OWN BOOKS MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            ViewOwnBooksMenu(library);
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



