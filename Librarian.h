#pragma once

#include "User.h"
class Library;

class Librarian : public User {
public:

    Librarian(string name, int number, int Passkey)
        : User(name, number, Passkey)
    {

    }


};


void ViewReport(Library& library);//NOT STARTED
void addBook(Library& library);
