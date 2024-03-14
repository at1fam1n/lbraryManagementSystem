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
    Book *arrayOfBooks; //pointer to array of books
    int numBooks;        //number of books currently in the library

    Library() : numBooks(0)
    {
        //initialize arrayOfBooks
        arrayOfBooks = new Book[1];//start with a size of 1, it will dynamically grow as needed
    }

    ~Library()
    {
        
        delete[] arrayOfBooks; //deallocate memory for array of books
    }

    void addBook(string bName, string aName)
    {
        string bid = generateId(); //generate ID for the book

        Book newBook;
        newBook.updateBook(bName, aName, bid);

        //create a new dynamic array with increased size
        Book *newArrayOfBooks = new Book[numBooks + 1];
        // copy old array to new array
        for (int i = 0; i < numBooks; ++i)
        {
            newArrayOfBooks[i] = arrayOfBooks[i];
        }
        // add new book
        newArrayOfBooks[numBooks] = newBook;

        //delete old array
        delete[] arrayOfBooks;

        //update arrayOfBooks and numBooks
        arrayOfBooks = newArrayOfBooks;
        numBooks++;

        cout << "Book stored in library:" << endl;
        cout << "Name: " << newBook.bookName << endl;
        cout << "Author: " << newBook.authorName << endl;
        cout << "ID: " << newBook.bookId << endl;

        filehandling.saveBookToExcelFile(newBook.bookName, newBook.authorName, newBook.bookId);
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

        cout << "YOUR BOOK ID IS :: " << id<<endl;

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
