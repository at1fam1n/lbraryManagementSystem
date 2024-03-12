#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
    string bookName;
    string authorName;
    string bookId;

    void updateBook(string newName, string newAuthor, string newId)
    {
        bookName = newName;
        authorName = newAuthor;
        bookId = newId;
    }

    void display()
    {
        cout << "Book Name"<< ","<< "Author Name"<<"," "Book Id" << endl;
        cout << bookName << "," << authorName << "," << bookId << endl;
    }
};