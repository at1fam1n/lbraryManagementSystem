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
    Book *arrayOfBooks; 
    int numBooks;       

    Library() : numBooks(0)
    {
        
        arrayOfBooks = new Book[1]; 
    }

    ~Library()
    {

        delete[] arrayOfBooks; 
    }




    void addBook(string bName, string aName)
    {
        string bid = generateId(); 

        Book newBook;
        newBook.updateBook(bName, aName, bid);

        
        Book *newArrayOfBooks = new Book[numBooks + 1];
        
                for (int i = 0; i < numBooks; ++i)
        {

            newArrayOfBooks[i] = arrayOfBooks[i];
        }
        
        newArrayOfBooks[numBooks] = newBook;

        
        delete[] arrayOfBooks;

        
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
        
        char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        const int idLength = 5; 
                string id;
        
                id.reserve(idLength);
        for (int i = 0; i < idLength; ++i)
        {
            id += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        return id;
    }

    void bookSearchById(string id)
    {

    }

    void bookSearchByName(string bookname)
    {

    }



     void borrowBook(string id)
    {

        char var;
        cout<<"IF YOU WANT TO BORROW BOOK ENTER Y/N :: ";
        cin>>var;
        if(var == 'y' || var == 'Y'){
            cout<<"STUDENT WANT TO BORROW BOOK "<<endl;
        }else if(var == 'n' || var == 'N'){
            cout<<"STUDENT DON'T WANT TO BORROW BOOK "<<endl;
        }else{
            cout<<"INVALID ANSWER "<<endl;
            return;
        }
        
        

        string studentName, studentSementer;
        int studentId;

        cout<<"ENTER YOUR NAME "<<endl;
        cin>>studentName;

        cout<<"ENTER YOUR STUDENT ID"<<endl;
        cin>>studentId;
        

        cout<<"ENTER YOUR CURRENT SEMESTER OR CLASS"<<endl;
        cin>>studentSementer;


        bool bookfound= false;

     for(int i=0;i<numBooks;i++){

        if(arrayOfBooks[i].bookId==id)

        {
            bookfound=true;
            break;
        }

     }
     if(bookfound){
        cout<<"BOOK IS AVAILABLE IN LIBRARY "<<endl;

     }else {
            cout << "CURRENTLY, THE BOOK IS NOT AVAILABLE IN THE LIBRARY BECAUSE SOMEONE HAS BORROWED IT. " << endl;
        }
    }




     void returnBook(string id)
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
        // find the book with the given ID and update its name and author
        for (int i = 0; i < numBooks; ++i)
        {
            if (arrayOfBooks[i].bookId == id)
            {
                arrayOfBooks[i].updateBook(newName, newAuthor, arrayOfBooks[i].bookId);
                filehandling.updateBook(id, newName, newAuthor, arrayOfBooks[i].bookId);
                return true;
            }
        }
        return false; // book not found
    }

    void displayAllBooks()
    {
        filehandling.retrieveBookFromExcelFile();
    }
};
