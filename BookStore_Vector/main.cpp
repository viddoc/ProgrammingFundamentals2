/*Tommy Hudson BookStore program
* 09/27/2023
* Program that will create a book class, instantiate, and ouput the data.
*The class will be in a separate file from the main
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

#include "bookbag.h"
#include "book.h"

void printBookBag(BookBag& bag)
{
	for (int i = 0; i < bag.getUniqueBookCount(); i++)
	{
		std::cout << bag[i] << std::endl;
	}
}

int main()
{
	//Name of file being imported.
	std::string fileName = "book_list.txt";
	//Vector to hold the Book objects.
	BookBag myBag("Joe Friday", "10/16/2023");
	//Open the input file.
	std::ifstream file(fileName);
	//Check if file opened properly
	if (!file)
	{
		std::cout << "Error. File not found.";
		exit(EXIT_FAILURE);
	}

	Book book;
	while (file >> book)
	{
		file.ignore();
		myBag.addBook(book);
	}

	//Output each book
	printBookBag(myBag);
	std::cout << myBag << std::endl;
	
	return 0;
}