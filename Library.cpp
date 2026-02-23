#include "Library.h"

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
/*
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
}*/
