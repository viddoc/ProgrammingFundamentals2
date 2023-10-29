/*Tommy Hudson BookStore program
* 09/27/2023
* Program that will create a book class, instantiate, and ouput the data.
* The entire class will be in one file and put main in the same file.
*/
#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	//Assign a default value to the instance variables
	string bookTitle{};
	double price{};

public:
	//Constructor
	Book(string bookTitle, double price) // list initializer
	{
		this->bookTitle = bookTitle;
		this->price = price;
	}
	/*
	* Alternate way to create constructor 
	* Book(string bookTitle, double price)
	*	: bookTitle(bookTitle), price(price){}
	*/
	Book() : Book("No title", 0.0) {} //To allow empty objects 
	//The above methods are called inlining meaning the code for the method is in the class definition.

	//Function to set a book title
	void setTitle(string bookTitle)
	{
		this->bookTitle = bookTitle;
	}
	//Function to get the book title
	string getTitle() const
	{
		return bookTitle;
	}
	//Different way to do inlining using inline function prototypes
	void setPrice(double price);
	double getPrice() const;
	
};
//Function to set book price
inline void Book::setPrice(double price)
{
	this->price = price;
}
//Function to get the book price
inline double Book::getPrice() const
{
	return price;
}


int main()
{
	//Different ways to construct the objects
	Book shining("The Shining", 19.95);
	Book book1;
	book1.setTitle("C++ for Profit and Pleasure");
	book1.setPrice(29.99);

	cout << book1.getTitle() << ": $" << book1.getPrice() << endl;
	cout << shining.getTitle() << ": $" << shining.getPrice() << endl;


	return 0;
}
