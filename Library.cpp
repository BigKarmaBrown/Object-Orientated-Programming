#include "Library.h"
#include <vector>
#include <algorithm>
void Library::addUser(const User& user)
{
    Users.push_back(user);
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
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              SEARCH BOOK BY NAME              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "                                             (Type 'Back' to go back)" << endl;
    cout << "                                             Enter book name:   ";

    string ans;
   // cin >> ans;
    getline(cin, ans);

    while (true) {
   if (ans == "back" || ans == "Back") {

            return;
        }
    auto it = find_if(Books.begin(), Books.end(), [&ans](const Book& book) {return book.getBookName() == ans;});
    if (it != Books.end()) 
    {
        cout << "book details are below: " << endl;
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
        system("pause");
        cin.clear();
        return;
    }
   
    else {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                                                    Book is not on the system" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "                                                 " << system("pause");
        break;
    }

    }
 
}