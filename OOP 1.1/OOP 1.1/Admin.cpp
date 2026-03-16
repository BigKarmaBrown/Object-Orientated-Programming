#include "Admin.h"
#include "Library.h"

void addLibrarian(Library& library)
{
    string tempLibrarianName;
    string tempLibrarianPasskey;
    bool tempReserved = false;
    cout << "What is the Librarians name? " << endl;
    cin >> tempLibrarianName;
   
    cout << "Please assign a Librarian Passkey!" << endl;
    cin >> tempLibrarianPasskey;
  

    Librarian newLibrarian(tempLibrarianName,  tempLibrarianPasskey);
    library.addLibrarian(newLibrarian);
    cout << "USER ADDED SUCCESFULLY" << endl;
    return;
}
void addAdmin(Library& library)
{
    string tempAdminName;
    string tempAdminPasskey;

    cout << "What is the Admins name? " << endl;
    cin >> tempAdminName;
  
    cout << "Please assign an Admin Passkey!" << endl;

    cin >> tempAdminPasskey;
    
    Admin newAdmin(tempAdminName, tempAdminPasskey);
    library.addAdmin(newAdmin);
    cout << "USER ADDED SUCCESFULLY" << endl;
    return;
}
