#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class FileHandling
{

public:
    void saveBookToExcelFile(string bookname, string authorname, string bookid)
    {
        ofstream file("text.csv", ios::out | ios::app);

        if (!file.is_open())
        {
            cout << "Error opening file" << endl;
            return;
        }

        file << "BookName," << "AuthorName," << "BookId" << endl;
        file << bookname << "," << authorname << "," << bookid << endl;

        cout << "Book added successfully!" << endl;
        file.close();
    }

    void retrieveBookFromExcelFile()
    {
        ifstream file("text.csv");

        if (!file.is_open())
        {
            cout << "Error: Could not open file." << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        cout << "Books retrieved successfully!" << endl;

        file.close();
    }

    bool deleteBook(string id)
    {
        ifstream inFile("text.csv");
        ofstream outFile("temp.csv");

        if (!inFile.is_open() || !outFile.is_open())
        {
            cout << "Error: Could not open file." << endl;
            return false;
        }

        string line;
        bool found = false;
        while (getline(inFile, line))
        {
            size_t position = line.find(id);
            if (position == string::npos)
            {
                outFile << line << endl;
            }
            else
            {
                found = true;
            }
        }

        inFile.close();
        outFile.close();

        if (found)
        {
            remove("text.csv");
            rename("temp.csv", "text.csv");
            cout << "Book deleted successfully!" << endl;
            return true;
        }
        else
        {
            cout << "Book not found!" << endl;
            remove("temp.csv");
            return false;
        }
    }




    bool updateBook(string id, string newName, string newAuthor, string newId)
    {
        ifstream inFile("text.csv");
        ofstream outFile("temp.csv");

        if (!inFile.is_open() || !outFile.is_open())
        {
            cout << "Error: Could not open file." << endl;
            return false;
        }

        string line;
        bool found = false;
        while (getline(inFile, line))
        {
            size_t position = line.find(id);
            if (position == string::npos)
            {
                outFile << line << endl;
            }
            else
            {
                outFile << newName << "," << newAuthor << "," << newId << endl;
                found = true;
            }
        }

        inFile.close();
        outFile.close();

        if (found)
        {
            remove("text.csv");
            rename("temp.csv", "text.csv");
            cout << "Book updated successfully!" << endl;
            return true;
        }
        else
        {
            cout << "Book not found!" << endl;
            remove("temp.csv");
            return false;
        }
    }
};
