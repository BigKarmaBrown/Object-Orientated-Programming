#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Book.h"
#include "Librarian.h"
#include "Admin.h"

using namespace std;
class Librarian;
class Admin;
class Library
{

public:
   vector<User> Users;
    vector<Book> Books;
    vector<Librarian> Librarians;
    vector<Admin> Admins;

    void addUser(const User& user);
    void addBook(const Book& book);
    void addLibrarian(const Librarian& librarian);
    void addAdmin(const Admin& admin);

   
    User* findUserByName(const string& name);
    Librarian* findLibrarianByName(const string& name);
    Admin* findAdminByName(const string& name);

  
};
