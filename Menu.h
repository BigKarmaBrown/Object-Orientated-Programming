#pragma once
#include "Admin.h"
#include "Librarian.h"
#include "User.h"
#include "Library.h"
#include "Book.h"
#include <iostream>


class Menu {

};

 
void loginMenu(Library& library);
void UserMainMenu(Library& library);
void AdminMainMenu(Admin* admin, Library& library);
void LibrarianMainMenu(Librarian* librarian, Library& library);
void loginMenu(Library& library);
void BrowseBooksMenu(Library& library); //PROGRESS
void ViewOwnBooksMenu(Library& library);
void ChangeBooksMenu(Library& library);
void ReservationsMenu(Library& library);//NOT STARTED
void ManageUserAccountsMenu(Library& library);
void ChangeSystemLimitationsMenu(Library& library);//NOT STARTED
void LibrarianLoginMenu(Library& library);
void AdminLoginMenu(Library& library);
void typeMenu(Library& library);
void usernameLogin(Library& library);
void changeBooksLimitMenu(Library& library);
void changeLatePenaltyMenu(Library& library);
void changeReservationsExpirationMenu(Library& library);
void ViewOwnBooksMenu(Library& library);