#include "Admin.h"
#include "Librarian.h"
#include "User.h"
#include "Library.h"
#include "Book.h"
#include "Menu.h"


  User createUser(string userName, int userNumber, int userPasskey)
    {
        User newUser(userName, userNumber, userPasskey);
        return newUser;

    }
    Book createBook(int bookID, string bookName, string bookAuthor, bool borrowed, bool reserved) {//LIBRARIAN AND ADMIN


        Book newBook(bookID, bookName, bookAuthor, borrowed, reserved);
        return newBook;
    }
int main() {

    Library library;

    library.addUser(User("Ollie", 1, 1234));
    library.addUser(User("Cam", 2, 2345));
    library.addUser(User("Ethan", 3, 3456));

    library.addBook(Book(1, "HandMaidsTale", "Margaret Atwood", false, false));
    library.addBook(Book(2, "Diary of a wimpy kid: Rodrick Rules", "Jeff Kinney", false, false));
    library.addBook(Book(3, "Diary of a wimpy kid:Dog days", "Jeff Kinney", false, false));
    library.addBook(Book(4, "The Bible", "Jesus", false, false));

    library.addLibrarian(Librarian("Peter", 0001, 1234));

    library.addAdmin(Admin("Guy", 0001, 3456));

    loginMenu(library);
    return 0;
}


