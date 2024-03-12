#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "library.h"

using namespace std;

int main()
{
    Library library;

    char op;

    do
    {
        cout << "ENTER 1 TO ADD BOOK ::" << endl;
        cout << "ENTER 2 TO RETRIEVE ALL BOOKS ::" << endl;

        cout << "ENTER 3 TO DELETE A BOOK BY ID ::" << endl;
        cout << "ENTER 4 TO UPDATE A BOOK ::" << endl;
        cout << "ENTER 5 TO EXIT ::" << endl;
        cout << "____________________________________" << endl;

        cout << "ENTER YOUR CHOICE :: ";
        cin >> op;

        switch (op)
        {

        case '1':
        {
            string newName, newAuthor, newId;
            cout << "ENTER NEW BOOK NAME: ";
            cin >> newName;
            cout << "ENTER NEW AUTHOR NAME: ";
            cin >> newAuthor;
            cout << "ENTER NEW BOOK ID: ";
            cin >> newId;
            library.addBook(newName, newAuthor, newId);
        }
        break;

        case '2':
        {
            library.displayAllBooks();
            break;
        }

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
            
        }

        case '5':
        {
            cout << "PROGRAM TERMINATED!" << endl;
            break;
        }

        default:
        {
            cout << "INVALID CHOICE! TRY AGAIN." << endl;
            break;
        }
        }

    } while (op != '6');

    return 0;
}
