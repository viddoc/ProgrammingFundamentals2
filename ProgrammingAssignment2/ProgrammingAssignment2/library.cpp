#include <iomanip>
#include "library.h"
#include "book.h"

Library::Library() : Library("") {}

Library::Library(std::string fileName)
	:fileName(fileName) 
{
	loadBooks(fileName);
}

void Library::loadBooks(std::string fileName)
{
	Book aBook("","","","");
	std::ifstream file(fileName);
	while (file >> aBook)
	{
		addBook(aBook);
	}
}

void Library::addBook(Book book)
{
	books.push_back(book);
}

void Library::checkBookOut(std::string numberISBN)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books.at(i).getISBN() == numberISBN)
		{
			books.at(i).updateStatus();
			break;
		}
	}
}

void Library::checkBookIn(std::string numberISBN)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books.at(i).getISBN() == numberISBN)
		{
			books.at(i).updateStatus();
			break;
		}
	}
}

void Library::printBookList()
{
	std::cout << std::left << std::setw(22) <<"  Author Name" << std::setw(44) <<"       Book Title" << std::setw(13) << "   ISBN" << "Availability\n"
		<< "--------------------------------------------------------------------------------------------\n";
	for (const Book& book : books)
	{
		std::cout << book << std::endl;
	}
	

}


std::ostream& operator << (std::ostream& out, const Library& library)
{
	
	return out;
}
