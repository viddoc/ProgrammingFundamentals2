#ifndef _LIBRARY_H_
#define	_LIBRARY_H_

#include <string>
#include <vector>
#include <iostream>
#include "book.h"

class Library
{
private:
	std::string fileName;
	std::vector<Book> books;

public:
    Library();
	Library(std::string fileName);

    void loadBooks(std::string fileName);
    void addBook(Book book);
    void checkBookOut(std::string numberISBN);
    void checkBookIn(std::string numberISBN);
    void printBookList();

	//Overloaded operators

    friend std::ostream& operator << (std::ostream& out, const Library& library);
};


#endif // !_LIBRARY_H_