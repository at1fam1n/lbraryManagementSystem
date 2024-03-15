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
    bool status;

    void updateBook(string newName, string newAuthor, string newId)
    {
        bookName = newName;
        authorName = newAuthor;
        bookId = newId;
    }

void borrowbook(){



}
    

    void display()
    {
       
        cout << bookName << "," << authorName << "," << bookId << endl;
    }
  
};