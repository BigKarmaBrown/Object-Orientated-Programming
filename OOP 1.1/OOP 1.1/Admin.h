#pragma once
#include <iostream>
using namespace std;
#include "Librarian.h"


class Library;
class Admin : public Librarian {
public:
    Admin(string name, string passkey)
        :Librarian(name, passkey)
    {
    }

};
void addLibrarian(Library& library);
void addAdmin(Library& library); 

