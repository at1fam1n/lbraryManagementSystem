#include <iostream>
#include <fstream>
#include <string>
#include "filehandling.h"
#include "book.h"
using namespace std;

class Library
{

public:
    FileHandling filehandling;
    Book book;
    Book book1[5];

    void addBook(string bName, string aName, string bid)
    {

        book.bookName = bName;
        book.authorName = aName;
        book.bookId = bid;

        cout << "book stored in library " << endl;
        cout << book.bookName ;
        cout << book.authorName ;
        cout << book.bookId ;

        filehandling.saveBookToExcelFile(book.bookName, book.authorName, book.bookId);
    }

    void bookSearchById(string id)
    {
    }

    void bookSearchByName(string bookname)
    {
    }

    static void borrowBook()
    {
    }

    static void returnBook(string id)
    {
    }

    void checkAvailabilityStatus()
    {
        
    }

    void deleteABook(string newbookid)
    {

        filehandling.deleteBook(newbookid);
    }

    void updateBook( string newName,  string newAuthor,  string newId)
    {
        book.updateBook(newName, newAuthor, newId);
       
    }

    void displayAllBooks()
    {

        book.display();

        filehandling.saveBookToExcelFile(book.bookName, book.authorName, book.bookId);
        filehandling.retrieveBookFromExcelFile();
    }
};