#pragma once

#include "User.h"
class Library;

class Librarian : public User {
public:

    Librarian(string name, string passkey)
        : User(name, passkey)
    {

    }


};


void ViewReport(Library& library);
void addBook(Library& library);
