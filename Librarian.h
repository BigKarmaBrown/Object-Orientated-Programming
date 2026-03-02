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


void ViewReport(Library& library);//NOT STARTED
void addBook(Library& library);
