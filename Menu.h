#pragma once
#include "Admin.h"
#include "Librarian.h"
#include "User.h"
#include "Library.h"
#include "Book.h"
#include <iostream>




 
void loginMenu(Library& library);
void UserMainMenu(User* user, Library& library);
void AdminMainMenu(Admin* admin, Library& library);
void LibrarianMainMenu(Librarian* librarian, Library& library);
void loginMenu(Library& library);
void BrowseBooksMenu(User* user, Library& library); //PROGRESS
void ViewOwnBooksMenu(User* user, Library& library);
void ChangeBooksMenu(Library& library);
void ReservationsMenu(Library& library);//NOT STARTED
void ManageUserAccountsMenu(Library& library);
void ChangeSystemLimitationsMenu(Library& library);//NOT STARTED
void LibrarianLoginMenu(Library& library);
void AdminLoginMenu(Library& library);
void typeMenu(Library& library);
void usernameLogin(Library& library);
