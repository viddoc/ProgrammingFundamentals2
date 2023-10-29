#ifndef _BOOKBAG_H_
#define	_BOOKBAG_H_

#include <string>
#include <vector>
#include <iostream>
#include "book.h"

class BookBag
{
private:
	std::string customerName;
	std::string currentDate;
	std::vector<Book> books;

public:
	BookBag(std::string customerName, std::string currentDate);

	//Getter methods
	std::string getCustomerName() const;
	std::string getDate() const;
	int getNumBooksInBag() const;
	double getCostOfBag() const;
	int getUniqueBookCount() const;

	//Action methods
	void addBook(Book book);
	void removeBook(std::string title, std::string description);
	void removeBook(Book book);
	void modifyBook(const Book& book);
	void printTotal() const;
	void printDescriptions() const;

	//Overloaded operators
	friend std::ostream& operator << (std::ostream& out, const BookBag& bag);
	BookBag operator + (BookBag rhs);
	BookBag operator + (Book rhs);
	BookBag operator - (Book rhs);
	Book& operator [] (int index);
};


#endif // !_BOOKBAG_H_

