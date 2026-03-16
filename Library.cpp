#include "Library.h"

#include <vector>
#include <algorithm>
void Library::addUser(const User& user)
{
    Users.push_back(user);
}

int Library::getBorrowedLimit() {
    return borrowedLimit;
}

void Library::setBorrowedLimit(int limit) {
    borrowedLimit = limit;
}

int Library::getreservationExpiration() {
    return reservationExpiration;
}

void Library::setreservationExpiration(int value) {
    reservationExpiration = value;
}
int Library::getBookBorrowedLength() {
    return bookBorrowedLength;
}

void Library::setBookBorrowedLength(int value) {
    bookBorrowedLength = value;
}

int Library::getlateFeePenalty() {
    return lateFeePenalty;
}

void Library::setlateFeePenalty(int value) {
    lateFeePenalty = value;
}


void Library::requestReservation(User* user, Book* book)
{
    reservationRequests.push_back(ReservationRequest(user, book));
    cout << "Reservation Request has been sent to the Librarian" << endl;
}


void Library::approveReservation(const string& name)
{
    for (auto& requests : reservationRequests) {
        if (requests.user->getUserName() == name) {
            requests.approved = true;
            requests.book->setReserved(true);

            cout << "Reservation has been aproved" << endl;
            system("Pause");
            return;
        }
        if (requests.book->getBookName() == name) {
            requests.approved = false;
            requests.book->setReserved(false);

            cout << "Reservation has been denied" << endl;
            system("Pause");
            return;
        }
    }

    cout << "Reservation not found" << endl;
}

void Library::printReservationRequests()
{
    for (int i = 0; i < reservationRequests.size(); i++)
    {
        cout << i << reservationRequests[i].user->getUserName() << "  Has requested" << endl;
        cout << "The Book: " << reservationRequests[i].book->getBookName() << endl;

    }
}


void Library::printOwnBooks(User* user) {
    for (auto* book : user->ownBook)
    {
        cout << "Book Name: " << book->getBookName() << endl;
        cout << "Book Author: " << book->getBookAuthor() << endl;
        cout << "Book ID: " << book->getBookID() << endl;
        cout << "" << endl;
        cout << endl;

    }
}

void Library::checkOverDueToBooks(User* user) {
    for (auto* book : user->ownBook)
    {
        string currentTime = "1";
        if (currentTime == book->getBookDueDate()) {
            cout << book->getBookName() << "is over due. Please return it from own books menu." << endl;
            cout << "If not you will be fined : " << getlateFeePenalty();
            cout << "" << endl;
          
        }
          system("Pause");
          continue;
    }
}
/*
void Library::decreaseBookDueDate() {
    
    //Use a time function to detect if a day has passed 
        for (auto* book : books) {
            book->setBookDueDate() = book->getBookDueDate() - 1;
            if (currentTime >= book->getBookDueDate)
            {
                book->setOverDue(true);
            }
            book->ReservationExpiration() = book->ReservationExpiration() - 1;
        }
    
}*/

void Library::returnOwnBooks(User* user, string name) {
    vector<Book*>& books = user->ownBook;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i]->getBookName() == name) {
            books[i]->setBorrowed(false);
            books.erase(books.begin() + i);


            cout << "Book has been returned" << endl;
            system("pause");
            
        }

    }
    cout << "book not found" << endl;

}




void Library::addBook(const Book& book)
{
    Books.push_back(book);
}

void Library::addLibrarian(const Librarian& librarian)
{
    Librarians.push_back(librarian);
}

void Library::addAdmin(const Admin& admin)
{
    Admins.push_back(admin);
}

User* Library::findUserByName(const string& name)
{
    for (auto& user : Users)
    {
        if (user.getUserName() == name)
            return &user;
    }
    return nullptr;
}

Librarian* Library::findLibrarianByName(const string& name)
{
    for (auto& librarian : Librarians)
    {
        if (librarian.getUserName() == name)
            return &librarian;
    }
    return nullptr;
}

Admin* Library::findAdminByName(const string& name)
{
    for (auto& admin : Admins)
    {
        if (admin.getUserName() == name)
            return &admin;
    }
    return nullptr;
}
Book* Library::findBookByName(const string& name)
{
    for (auto& book : Books)
    {
        if (book.getBookName() == name)
            return &book;
    }
    return nullptr;
}


void Library::setCurrentUser(User* user)
{
    currentUser = user;
}
User* Library::getCurrentUser()
{
    return currentUser;
}    
void Library::logout()
{
    currentUser = 0;
}

void Library::removeUser()
{
    string tempUser;
    string yesNo;
    
   
    cout << "Which User Would you like to get rid of?" << endl;
    cin >> tempUser;

  


    cout << "Are these details correct? " << endl;
    cout << "User Name: " << tempUser << endl;
    
    
    cin >> yesNo;
    if (yesNo == "No" || yesNo == "no" || yesNo == "N" || yesNo == "n" || yesNo == "NO")
    {
        cout << "please try again" << endl;
        return;
        
    }

    if (yesNo == "Yes" || yesNo == "yes" || yesNo == "Y" || yesNo == "y" || yesNo == "YES")
    {
        

        for (auto it = Users.begin(); it != Users.end(); ++it)
        {
            if (it->getUserName() == tempUser)
            {
                Users.erase(it);
                cout << "User has been erased! " << endl;
                return;
            }
            else
            {
               
                cout << "Invalid input" << endl;
                return;
            }
        }
        
    }
    else
    {
        cout << "Invalid Input, Please try again!" << endl;
        
        return;
    }

}
void Library::removeBook() 
{
    string tempBook;
    string yesNo;
    string tempID;

    cout << "Which Book Would you like to get rid of?" << endl;
    cin >> tempBook;

    cout << "Whats the Books ID?" << endl;
    cin >> tempID;


    cout << "Are these details correct? " << endl;
    cout << "Book Name: " << tempBook << endl;
    cout << "Book ID: " << tempID << endl;

    cin >> yesNo;
    if (yesNo == "No" || yesNo == "no" || yesNo == "N" || yesNo == "n" || yesNo == "NO")
    {
        cout << "please try again" << endl;
        return;

    }

    if (yesNo == "Yes" || yesNo == "yes" || yesNo == "Y" || yesNo == "y" || yesNo == "YES")
    {


        for (auto it = Books.begin(); it != Books.end(); ++it)
        {
            if (it->getBookName() == tempBook &&
                it->getBookID() == tempID)
            {
                Books.erase(it);
                cout << "Book has been erased! " << endl;
                return;
            }
            else
            {


            }
        }
        cout << "Invalid input" << endl;
    }
    else
    {
        cout << "Invalid Input, Please try again!" << endl;

        return;
    }

}
void Library::searchBookName() {
    system("CLS");

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               SEARCH BOOK BY NAME/AUTHOR                ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                                           (Type 'Back' to go back)" << endl;
    cout << "                                           Enter book name/author:   ";

    string ans;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, ans);

    while (true) {
   if (ans == "back" || ans == "Back") {

            return;
        }
    for (int i = 0; i < Books.size(); i++) 
    {
        auto it = find_if(Books.begin(), Books.end(), [&ans](const Book& book) {return book.getBookName() == ans || book.getBookAuthor() == ans;});

        if (it == Books.end()) {
            cout << "Inavlid input! Returning menu!" << endl;
            system("Pause");
            return;
        }
        
            cout << "Book details are below: " << endl;
            cout << "Book Name: " << it->getBookName() << endl;
            cout << "Book Author: " << it->getBookAuthor() << endl;
            cout << "Book Borrowed: " << endl;
            if (it->getBorrowed() == true)
            {
                cout << "Yes" << endl;

            }
            else
            {
                cout << "No" << endl;
            }
            cout << "Book Reserved: " << endl;
            if (it->getReserved() == true)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            cout << " " << endl;
            cout << " " << endl;
            cout << " " << endl;
            

            system("Pause");
            return;
    }
  

    }

    
 
}