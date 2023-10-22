//Header guard
#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>
#include <iostream>
#include<fstream>

class Book
{
	//Default blank values assigned to instance variables
private:
	std::string numberISBN{};
	std::string bookTitle{};
    std::string authorLast{};
    std::string authorFirst{};
    std::string bookStatus{};
	//Constructors
public:
	Book(std::string numberISBN, std::string bookTitle, std::string authorLast, std::string authorFirst);

    std::string getISBN() const;
	std::string getTitle() const;
	std::string getLast() const;
    std::string getFirst() const;
    std::string getStatus() const;
	void updateStatus();
	
	//Overloads << and >> for cout and cin
	friend std::ostream& operator << (std::ostream& out, const Book& book);
	friend std::istream& operator >> (std::istream& in, Book& book);
};

#endif // !_BOOK_H_