#include <iostream>
#include <fstream>
#include <string>
#include "filehandling.h"
#include "book.h"
using namespace std;

int numBooks=0; //number of books currently in the library

class Library
{

    public:

    FileHandling filehandling;
    static const int MAX_BOOKS = 100; //maximum number of books in the library
    Book arrayOfBooks[MAX_BOOKS];     //array of books

    void addBook(string bName, string aName)
{
    if (numBooks < MAX_BOOKS)
    {
        string bid = generateId(); // Generate ID for the book
        arrayOfBooks[numBooks].updateBook(bName, aName, bid);

        cout << "Book stored in library:" << endl;
        cout << "Name: " << arrayOfBooks[numBooks].bookName << endl;
        cout << "Author: " << arrayOfBooks[numBooks].authorName << endl;
        cout << "ID: " << arrayOfBooks[numBooks].bookId << endl;

        filehandling.saveBookToExcelFile(arrayOfBooks[numBooks].bookName, arrayOfBooks[numBooks].authorName, arrayOfBooks[numBooks].bookId);

        numBooks++;
    }
    else
    {
        cout << "Maximum number of books reached." << endl;
    }
}


    string generateId()
    {
        //generate random ID for book
         char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        const int idLength = 5; // Set the length of the ID
        string id;
        id.reserve(idLength);
        for (int i = 0; i < idLength; ++i)
        {
            id += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        cout<<"YOUR BOOK ID IS :: "<<id;

        return id;
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

   bool updateBook(string id, string newName, string newAuthor)
{
    //find the book with the given ID and update its name and author
    for (int i = 0; i < numBooks; ++i)
    {
        if (arrayOfBooks[i].bookId == id)
        {
            arrayOfBooks[i].updateBook(newName, newAuthor, arrayOfBooks[i].bookId);
            filehandling.updateBook(id, newName, newAuthor, arrayOfBooks[i].bookId);
            return true;
        }
    }
    return false; //book not found
}


    void displayAllBooks()
    {
        filehandling.retrieveBookFromExcelFile();
    }
};
