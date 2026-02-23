#pragma once
#include <iostream>
using namespace std;
#include "Librarian.h"


class Library;
class Admin : public Librarian {
public:

    

    Admin(string name, int number, int Passkey)
        :Librarian(name, number, Passkey) {
    }


};
void removeUser(Library& library);//NOT STARTED
void addLibrarian(Library& library);
void addAdmin(Library& library); 

