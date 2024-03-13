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
    //Book arrayOfBook[10];

    void addBook(string bName, string aName, string bid)
    {
        book.bookName = bName;
        book.authorName = aName;
        book.bookId = bid;

        cout << "Book stored in library:" << endl;
        cout << "Name: " << book.bookName << endl;
        cout << "Author: " << book.authorName << endl;
        cout << "ID: " << book.bookId << endl;

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

    bool updateBook(string id, string newName, string newAuthor, string newId)
    {
        return filehandling.updateBook(id, newName, newAuthor, newId);
    }

    void displayAllBooks()
    {
        filehandling.retrieveBookFromExcelFile();
    }
};
