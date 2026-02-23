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
    library.addBook(Book(5, "Lord of the rings", "J.R.R Tolkien", false, false));
    library.addBook(Book(6, "HarryPotter: Philosphers Stone", "J.K Rowling", false, false));
    library.addBook(Book(7, "Pride and prejudice", "Jane Austen", false, false));
    library.addBook(Book(8, "Romeo and Juliet", "William Shakespeare", false, false));
    library.addBook(Book(9, "Great Expectations", "Charles Dickins", false, false));
    library.addBook(Book(10, "1984","George Orwell", false, false));
    library.addBook(Book(11, "Animal Farm", "George Orwell", false, false));
    library.addBook(Book(12, "Doctor sleep","Stephen King", false, false));
    library.addBook(Book(13, "It", "Stephen King", false, false));
    library.addBook(Book(14, "The Shining", "Stephen King", false, false));
    library.addBook(Book(15, "The green mile", "Stephen King", false, false));
    library.addBook(Book(16, "Cross", "James Patterson", false, false));
    library.addBook(Book(17, "Along Came a spider", "James Patterson", false, false));
    library.addBook(Book(18, "Kiss the grils", "James Patterson", false, false));
    library.addBook(Book(19, "I funny", "James Patterson", false, false));
    library.addBook(Book(20, "The quickie", "James Patterson", false, false));


    library.addLibrarian(Librarian("Peter", 0001, 1234)); 
    library.addLibrarian(Librarian("Luke", 0002, 3333));

    library.addAdmin(Admin("Guy", 0001, 3456));
    library.addAdmin(Admin("Hakan", 0002, 1066));

    loginMenu(library);
    return 0;
}


