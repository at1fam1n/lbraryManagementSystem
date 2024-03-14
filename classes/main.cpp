#include <iostream>
#include <string>
#include "library.h"

using namespace std;

int main()
{
    Library library; // Create the library object

    char op;

    do
    {
        cout << "ENTER 1 TO ADD BOOK ::" << endl;
        cout << "ENTER 2 TO RETRIEVE ALL BOOKS ::" << endl;
        cout << "ENTER 3 TO DELETE A BOOK BY ID ::" << endl;
        cout << "ENTER 4 TO UPDATE A BOOK ::" << endl;
        cout << "ENTER 5 TO CHECK AVAILABILITY ::" << endl;
        cout << "ENTER 6 TO EXIT ::" << endl;
        cout << "____________________________________" << endl;

        cout << "ENTER YOUR CHOICE :: ";
        cin >> op;

        switch (op)
        {

       case '1':
{
    string newName, newAuthor;
    cout << "ENTER NEW BOOK NAME: ";
    cin.ignore(); // Ignore the newline character left in the input stream
    getline(cin, newName);
    cout << "ENTER NEW AUTHOR NAME: ";
    getline(cin, newAuthor);
    library.addBook(newName, newAuthor);
    library.generateId();
    
}
break;


        case '2':
        {
            library.displayAllBooks();
        }
        break;

        case '3':
        {
            string bookId;
            cout << "ENTER BOOK ID TO DELETE: ";
            cin >> bookId;
            library.deleteABook(bookId);
        }
        break;

        case '4':
{
    string id, newName, newAuthor;
    cout << "ENTER BOOK ID TO UPDATE: ";
    cin >> id;
    cout << "ENTER NEW BOOK NAME: ";
    cin.ignore(); //ignore the newline character left in the input stream
    getline(cin, newName);
    cout << "ENTER NEW AUTHOR NAME: ";
    getline(cin, newAuthor);
    if (library.updateBook(id, newName, newAuthor))
        cout << "Book updated successfully!" << endl;
    else
        cout << "Book not found!" << endl;
}
break;

        case '5':
        {
            library.checkAvailabilityStatus();
        }
        break;

        case '6':
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "INVALID CHOICE! TRY AGAIN." << endl;
            break;
        }

    } while (op != '6');

    return 0;
}
