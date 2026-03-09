#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Book.h"
#include "Librarian.h"
#include "Admin.h"
#include "Reservations.h"

using namespace std;

class Library
{

public:

    vector<User> Users;
    vector<Book> Books;
    vector<Librarian> Librarians;
    vector<Admin> Admins;
    vector<ReservationRequest> reservationRequests;

    void addUser(const User& user);
    void addBook(const Book& book);
    void addLibrarian(const Librarian& librarian);
    void addAdmin(const Admin& admin);
    void removeUser();
    void removeBook();
    void searchBookName();

    User* findUserByName(const string& name);
    Librarian* findLibrarianByName(const string& name);
    Admin* findAdminByName(const string& name);
    Book* findBookByName(const string& name);


    int getBorrowedLimit();
    void setBorrowedLimit(int limit);
    int getreservationExpiration();
    void setreservationExpiration(int value);
    int getlateFeePenalty();
    void setlateFeePenalty(int value);

    void requestReservation(User* user, Book* book);
    void approveReservation(const string& bookName);
    void printReservationRequests();
    void printOwnBooks(User* user);
    void returnOwnBooks(User* user, string name);

    User* currentUser = nullptr;
    void setCurrentUser(User* user);
    User* getCurrentUser();
    void logout();

private:
    int borrowedLimit = 5;
    int reservationExpiration = 3;
    int lateFeePenalty = 50;

};
