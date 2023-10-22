/******************************
*  Name Tommy Hudson
*  Date 10/22/2023
*  File Name main.cpp
*  Description: Program designed to buiild a library of books from a text file
*  and allow books to be checked out, checked in, or added through the console.
********************************/

// Headers
#include <iostream>
#include <string>
#include <limits>
using namespace std;

#include "book.h"		// for a book type
#include "library.h"	// for a library type

// Global variables
const string FILENAME = "BookFile.txt";		// name of file that contains book info

// Function declarations
void addBook(Library & lib);

int main()
{
	Library library(FILENAME);	// create a library of books
	char choice;				// user's menu choice
	string ISBN;				// ISBN value to search for

	// loop until we want to quit
	do
	{
		cout << "Main Menu\n";
		cout << "1. Print Book List\n";
		cout << "2. Check out a book\n";
		cout << "3. Check in a book\n";
		cout << "4. Add a book\n";
		cout << "5. Quit\n";
		cout << "Enter your choice (1-5): ";
		cin >> choice;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');	// flush the stream

		switch (choice)
		{
		case '1':	// Print the list
			library.printBookList();
			break;

		case '2':	// Check out a book
			cout << "Enter the ISBN of the book to ckeck out: ";
			cin >> ISBN;
			library.checkBookOut(ISBN);
			cout << endl;
			break;

		case '3':	// Check book in
			cout << "Enter the ISBN of the book to check in: ";
			cin >> ISBN;
			library.checkBookIn(ISBN);
			cout << endl;
			break;

		case '4':	// Add a book
			addBook(library);
			break;

		case '5':	// Quit
			break;

		default:
			cout << "Not a valid option. Please try again\n\n";
			break;

		}

		if (choice != '5')
		{
			system("PAUSE");
			system("CLS");
		}

	} while (choice != '5');
    
    
	//	Make sure we place the end message on a new line
    cout << endl;
	
    return 0;
}

// This function will prompt the user for information about a book to be added
// It will use the information to create a book and add it to Library lib
void addBook(Library & lib)
{
	string ISBN;				// ISBN number of book
	string authorLastName;		// Author last name
	string authorFirstName;		// Author first name
	string title;				// Title of the book

	cout << "Enter the ISBN of the book: ";
	cin >> ISBN;

	cout << "Enter the last name of the author: ";
	cin >> authorLastName;

	cout << "Enter the first name of the author: ";
	cin >> authorFirstName;

	getchar();		// need to clear the newline before calling getline
	cout << "Enter the title of the book: ";
	getline(cin, title);

	// Create book and add to the library
	lib.addBook(Book(ISBN, title, authorLastName, authorFirstName));
}
