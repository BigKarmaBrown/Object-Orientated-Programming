#include "Admin.h"
#include "Library.h"
void removeUser(Library& library)
{
    bool correctDetails;
    string tempUser;
    int tempID;

    cout << "Which User Would you like to get rid of?" << endl;
    cin >> tempUser;

    //compare tempUser to User Library


    cout << "Whats the Users ID?" << endl;
    cin >> tempID;

    //compare tempID to User Library


    cout << "Are these details correct? " << endl;
    cout << "User Name: " << tempUser << endl;
    cout << "User ID: " << tempID << endl;
    cin >> correctDetails;
    if (!correctDetails) {
        cout << "Please try again. " << endl;
        return;
    }
    cout << "User Succesfully removed! " << endl;
    return;

}
void addLibrarian(Library& library)
{
    string tempLibrarianName;
    int tempLibrarianPasskey = 0;
    int tempLibrarianNumber = 0;
    bool tempReserved = false;
    cout << "What is the Librarians name? " << endl;
    if (!(cin >> tempLibrarianName))
    {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else
    {

    }
    cout << "Please assign a Librarian Numeber!" << endl;
    cout << "(less than 100000000)" << endl;
    cin >> tempLibrarianNumber;
    if (tempLibrarianNumber >= 100000000 || tempLibrarianNumber <= 0) {
        cout << "invalid input! Please try again." << endl;

    }
    else
    {

    }
    cout << "Please assign a Librarian Passkey!" << endl;
    cout << "(less than 100000000)" << endl;
    cin >> tempLibrarianPasskey;
    if (tempLibrarianPasskey >= 100000000 || tempLibrarianPasskey <= 0) {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else
    {

    }

    Librarian newLibrarian(tempLibrarianName, tempLibrarianNumber, tempLibrarianPasskey);
    library.addLibrarian(newLibrarian);
    cout << "USER ADDED SUCCESFULLY" << endl;
    return;
}
void addAdmin(Library& library)
{
    string tempAdminName;
    int tempAdminPasskey = 0;
    int tempAdminNumber = 0;
    bool tempReserved = false;
    cout << "What is the Admins name? " << endl;
    if (!(cin >> tempAdminName))
    {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else
    {

    }
    cout << "Please assign an Admin Numeber!" << endl;
    cout << "(less than 100000000)" << endl;
    cin >> tempAdminNumber;
    if (tempAdminNumber >= 100000000 || tempAdminNumber <= 0) {
        cout << "invalid input! Please try again." << endl;

    }
    else
    {

    }
    cout << "Please assign an Admin Passkey!" << endl;
    cout << "(less than 100000000)" << endl;
    cin >> tempAdminPasskey;
    if (tempAdminPasskey >= 100000000 || tempAdminPasskey <= 0) {
        cout << "invalid input! Please try again." << endl;
        return;
    }
    else
    {

    }

    Admin newAdmin(tempAdminName, tempAdminNumber, tempAdminPasskey);
    library.addAdmin(newAdmin);
    cout << "USER ADDED SUCCESFULLY" << endl;
    return;
}
