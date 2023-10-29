//Header guard
#ifndef _BOOK_VECTOR_H_
#define _BOOK_VECTOR_H_

#include <string>
#include <iostream>

class Book
{
	//Default blank values assigned to instance variables
private:
	std::string bookTitle{};
	double price{};
	int quantity{};
	std::string description{};
	//Constructors
public:
	Book();
	Book(std::string bookTitle, std::string description, double price, int quantity);

	void setTitle(std::string bookTitle);
	std::string getTitle() const;
	void setPrice(double price);
	double getPrice() const;
	void setQuantity(int quantity);
	int getQuantity() const;
	void setDescription(std::string description);
	std::string getDescription() const;

	void printBookTitleAndCost() const;
	void printBookDescription() const;
	//Overloads << and >> for cout and cin
	friend std::ostream& operator << (std::ostream& out, const Book& book);
	friend std::istream& operator >> (std::istream& in, Book& book);
	//Overload some relational operators
	friend bool operator  == (const Book& lhs, const Book& rhs);
	friend bool operator  != (const Book& lhs, const Book& rhs);
	friend bool operator  < (const Book& lhs, const Book& rhs);
	friend bool operator  > (const Book& lhs, const Book& rhs);
};

#endif // !_BOOK_VECTOR_H_
